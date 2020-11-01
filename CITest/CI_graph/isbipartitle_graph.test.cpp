#include <bits/stdc++.h>
#include "../../src/data_structure/isbipartitle_graph.cpp"
#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2885
using namespace std;
bool solve(){
    int N,M;
    cin >> N >> M;
    if(N + M == 0) return false;
    vector<vector<int>>edge(N);
    for(int i = 0; i < M; ++i){
        int u,v; cin >> u >> v;
        --u,--v;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    if(not isbipartitle_graph(edge)){
        cout << 0 << endl;
        return true;
    }
    vector<int>d(N,inf);
    queue<pair<int,int>>que;
    que.emplace(0,-1);
    while(not que.empty()) {
        int v,dist;
        tie(v,dist) = que.front();
        que.pop();
        if(d[v] != inf) continue;
        d[v] = dist + 1;
        for(const auto nv : edge[v]) {
            que.emplace(nv,dist + 1);
        }
    }
    int remu = 0, ramu = 0;
    for(const auto clr  :  d)
        ++(clr % 2   ?  remu : ramu);
    set<int>S;
    if(remu % 2 == 0) S.insert(remu/2);
    if(ramu % 2 == 0) S.insert(ramu/2);
    S.erase(0);
    cout << S.size() << endl;
    for(auto itr : S)
        cout << itr << endl;
    return true;
}
int main(){
    while(solve());
    
}
