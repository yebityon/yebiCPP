#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
struct Edge{ int to,cap,rev;};

class Dinic{//max flow
public:
    int n;
    vector<vector<Edge>>G;
    vector<int> level,iter;
    Dinic(int size): n(size),G(vector<vector<Edge>>(n)){};
    void add_Edge(int from, int to, int cap){
        Edge q={to,cap,int(G[to].size())};
        G[from].emplace_back(q);
        q={from,0,int(G[from].size()-1)};
        G[to].emplace_back(q);
    }
    void bfs(int s){
        level=vector<int>(n,-1);
        queue<int>q;
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int v=q.front();q.pop();
            for(auto &e :G[v]){
                if(e.cap>0&&level[e.to]<0){
                    level[e.to]=level[v]+1;
                    q.push(e.to);
                }
            }
        }
    }
    function<int(int,int,int)>dfs = [&](int v, int t, int f) -> int{
        if(v==t)return f;
        for(;iter[v]<G[v].size();iter[v]++){
            Edge &e=G[v][iter[v]];
            if(level[v]>=level[e.to]||e.cap<=0) continue;
            int d =dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
        return 0;
    };
    int max_flow(int s,int t) {//from s to t,ford_fulkerson
        int flow=0;
        while(1){
            bfs(s);
            if(level[t]<0)return flow;
            iter=vector<int>(n);
            int f;
            while((f=dfs(s,t,INF))>0)flow+=f;
        }
    };
};



