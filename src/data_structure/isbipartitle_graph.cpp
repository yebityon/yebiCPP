#include <bits/stdc++.h>
constexpr int inf = 1e9;
using namespace std;
class unionfind {
    vector<int> par, rank, size_;
public:
    unionfind(int n) :par(n), rank(n), size_(n, 1) {
        iota(par.begin(),par.end(), 0);
    }
    int find(int x) {
        if (par[x] == x)return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)return;
        if (rank[x] < rank[y])swap(x, y);
        par[y] = x;
        size_[x] += size_[y];
        if (rank[x] == rank[y])rank[x]++;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return size_[find(x)];
    }
};
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
