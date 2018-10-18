#include<bits/stdc++.h>
//最小有向全域木(Chu-Liu/Edmondsのアルゴリズム)
using namespace std;
#define rep(i,n)  for(int i=0;i<n;i++)
using pii = pair<int, int>;
using piii = pair<pii, int>;
using Edge  = pair<int, pii>;
using ll = long long;
const int INF=1e9;
#define mp make_pair
//define int ll
ll Chu_Liu_Edmonds(vector<Edge>edge, int V,int start){
    vector<pii>mins(V,mp(INF,-1));
    rep(i,edge.size()){
        Edge now=edge[i];
        mins[now.second.second]=min(mins[now.second.second],mp(now.first,now.second.first));
    }
    mins[start]=mp(-1,-1);
    vector<int>group(V,0);
    vector<bool>IsCycle(V,false);
    int count=0;
    vector<bool>IsUsed(V,false);
    rep(i,V){
        //頂点iから有向木を辿っていく
        if(IsUsed[i])continue;
        vector<int>chain;
        int cursor=i;
        while(cursor!=-1&&!IsUsed[cursor]){
            //頂点から辿っていく
            IsUsed[cursor]=true;
            chain.emplace_back(cursor);
            //cursor
            cursor=mins[cursor].second;
        }
        if(cursor!=-1){
            //頂点にたどり着かなかったー＞閉路の可能性あり
            bool InCycle=false;
            rep(j,chain.size()){
                //任意の点が２つ以上の閉路に入ることは無い
                group[chain[j]]=count;
                //chan[j]がcursorに突入→同じ頂点に戻ってくるので閉路突入
                if(chain[j]==cursor){
                    //countが振られたvertexは閉路内にある
                    IsCycle[count]=true;
                    InCycle=true;
                }
                if(!InCycle)count++;
            }
            if(InCycle)count++;
        }else{
            //根で終了した→閉路が見つからない
            rep(j,chain.size()){
                group[chain[j]]=count;
                count++;
            }
        }
    }
    // グループ分けの終了
    if(count==V){
        ll ans=1;
        rep(i,V)ans+=mins[i].first;
        return ans;
    }
    //縮約した閉路のコストの合計を計算
    ll res=0;
    rep(i,V){
        //頂点のコストは-1が入っているため
        if(i!=start&&IsCycle[group[i]]){
            res+=mins[i].first;
        }
    }
    //新たにグラフを構成して再帰的にコストを求める
    //グループ分け→新たに頂点を降る
    vector<Edge>newEdge;
    rep(i,edge.size()){
        Edge _edge=edge[i];
        int to=_edge.second.second;
        int gfrom=group[_edge.second.first];
        int gto=group[_edge.second.second];
        if(gfrom==gto)continue; //同じ閉路にある頂点は追加しなくて良い
        else if(IsCycle[gto])
            newEdge.push_back(mp(_edge.first-mins[to].first,mp(gfrom,gto)));
        else newEdge.push_back((mp(_edge.first,mp(gfrom,gto))));
        
    }
    return res+Chu_Liu_Edmonds(newEdge, count, group[start]);
}
int main(){}

