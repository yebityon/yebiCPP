#include <bits/stdc++.h>
using namespace std;

auto TopologicalSort(vector<vector<int>>&edge){
    int N = edge.size();
    vector<int>v(N,false);
    vector<int>out(N);
    int idx = N-1;
    function<void (int)>dfs = [&](int u) -> void{
        v[u] = true;
        for(int i = 0; i < edge[u].size();i++){
            int nv = edge[u][i];
            if(!v[nv])dfs(nv);
        }
        out[idx--] = u;
    };
    for(int i = 0; i < v.size();i++){
        if(!v[i])dfs(i);
    }
    return out;
}
