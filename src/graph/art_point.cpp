#include<bits/stdc++.h>
einclude<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
//#define int ll
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
#define mp make_pair
#define MAX 100000
class art_point{
private:
    art_point(int V,vector<vector<int>>&E){
        prenum.resize(V);
        parent.resize(V);
        lowest.resize(V);
        timer=0;
        visited.resize(V);
        rep(i,V)visited[i]=false;
        edge=E;
        N=v=V;
        get_art_point();
    }
    void dfs(int current,int prev){
        prenum[current]=lowest[current]=timer;
        timer++;
        visited[current]=true;
        int  next;
        for(int i=0;i<edge[current].size();i++){
            next=edge[current][i];
            if(!visited[next]){
                parent[next]=current;
                dfs(next,current);
                lowest[current]=min(lowest[current],lowest[next]);
            }else if(next != prev){
                lowest[current] = min(lowest[current],prenum[next]);
            }
        }
    }
    void get_art_point(){
        timer=1;
        dfs(0,-1);
        int np=0;
        for(int i=1;i<N;i++){
            int p=parent[i];
            if(p==0)np++;
            else if(prenum[p]<=lowest[i])Mp[p]++;
            if(np>1)Mp[0]++;
        }
    }
public:
    vector<bool>visited;
    vector<int>prenum;
    vector<int>parent;
    vector<int>lowest;
    int timer;
    int v;
    int N;
    map<int,int>Mp;
    vector<vector<int>>edge;
    //member fucntion
    void show_art_point(){
        for(auto itr:Mp)cout<<itr.first<<endl;
    }
    map<int,int>get(){return Mp;}
};
signed main(){
    int v,e; cin>>v>>e;
    vector<vector<int>>edge(v);
    rep(i,e){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
//#define int ll
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
#define mp make_pair
#define MAX 100000
class art_point{
private:
    void dfs(int current,int prev){
        prenum[current]=lowest[current]=timer;
        timer++;
        visited[current]=true;
        int  next;
        for(int i=0;i<edge[current].size();i++){
            next=edge[current][i];
            if(!visited[next]){
                parent[next]=current;
                dfs(next,current);
                lowest[current]=min(lowest[current],lowest[next]);
            }else if(next != prev){
                lowest[current] = min(lowest[current],prenum[next]);
            }
        }
    }
    void get_art_point(){
        timer=1;
        dfs(0,-1);
        int np=0;
        for(int i=1;i<N;i++){
            int p=parent[i];
            if(p==0)np++;
            else if(prenum[p]<=lowest[i])Mp[p]++;
            if(np>1)Mp[0]++;
        }
    }
public:
    vector<bool>visited;
    vector<int>prenum;
    vector<int>parent;
    vector<int>lowest;
    int timer;
    int v;
    int N;
    map<int,int>Mp;
    vector<vector<int>>edge;
    //member fucntion
    art_point(int V,vector<vector<int>>&E){
        prenum.resize(V);parent.resize(V);lowest.resize(V);
        visited.resize(V);
        rep(i,V)visited[i]=false;
        edge=E;
        N=v=V;
        get_art_point();
    }
    void show_art_point(){
        for(auto itr:Mp)cout<<itr.first<<endl;
    }
    map<int,int>get(){return Mp;}
};
signed main(){
    int v,e; cin>>v>>e;
    vector<vector<int>>edge(v);
    rep(i,e){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    art_point hoge(1,edge);
}

