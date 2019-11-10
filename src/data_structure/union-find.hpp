#include<bits/stdc++.h>

//union-findのクラス
class unionfind {
    vector<int> par, rank, size_;//速度ではなくメモリ効率を考えるならrankのかわりにsizeを使う
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

