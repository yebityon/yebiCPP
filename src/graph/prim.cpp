#include<bits/stdc++.h>
using namespace std;
class Prim{
public:
    vector<vector<pair<int,int>>>edge;
    int res = 0;
    Prim(vector<vector<pair<int,int>>>&e): edge(e){
        vector<bool>used(e.size(),false);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>que;
        que.push(make_pair(0, 0));
        while(!que.empty()){
            int v = que.top().second;
            int cost = que.top().first;
            que.pop();
            if(used[v])continue;
            res += cost;
            for(auto & e : edge[v]){
                if(not used[e.first])
                    que.push(make_pair(e.second,e.first));
            }
            used[v] = true;
        }
    };
    auto getval(){return res;}
    
};
signed main(){
    int v,e; cin >> v >> e;
    vector<vector<pii>>t(v);
    rep(i,e){
        int a,b,c;cin >> a>> b>> c;
        t[a].push_back(pii(b,c));
        t[b].push_back(pii(a,c));
    }
    Prim p(t); cout << p.getval() << endl;
}



