#include<bits/stdc++.h>
using namespace std;
#include"../../src/graph/Kruskal.cpp"
int main(){
    int v,e; cin >> v >> e;
    vector<vector<pair<int,int>>>edge(v);
    for(int i = 0; i < e ; ++ i){
        int s,t,w; cin >> s >> t >> w;
        edge[s].emplace_back(t,w);
    }
    cout << Kruskal(edge) << endl;
}

