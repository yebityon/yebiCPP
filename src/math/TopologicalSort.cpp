#include <bits/stdc++.h>
//main(){};
// not verify

auto TopologicalSort(int n){
    vector<int>v(n,false);
    vector<int>out(n);
    int idx = n-1;
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
