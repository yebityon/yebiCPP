#include <bits/stdc++.h>
#include "../../src/data_structure/union-find.hpp"
constexpr int inf = 1e9;
using namespace std;
bool isbipartitle_graph(vector<vector<int>>&edge){
    int N = static_cast<int>(edge.size());
    auto uf = unionfind(N * 2);
    for(int u = 0; u < N; ++u){
        for(auto v : edge[u]){
            if(u > v) continue;
            uf.unite(u,v + N);
            uf.unite(u + N, v);
        }
    }
    for(int v = 0; v < N; ++v)
        if(uf.same(v,v + N)) return false;
    return true;
}
