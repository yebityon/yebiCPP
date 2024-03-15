#include <bits/stdc++.h>
using namespace std;

auto TopologicalSort(vector<vector<int>> &edge) {
    int N = edge.size();
    vector<int> v(N, false);
    vector<int> out(N);
    int idx                 = N - 1;
    function<void(int)> dfs = [&](int u) -> void {
        v[u] = true;
        for (int i = 0; i < edge[u].size(); i++) {
            int nv = edge[u][i];
            if (!v[nv]) dfs(nv);
        }
        out[idx--] = u;
    };
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]) dfs(i);
    }
    return out;
}

template <typename T> 
vector<T> TopologicalSortBfs(vector<vector<T>> &edge) {
    const size_t N = edge.size();
    vector<T> in(N,T(0)), out;
    queue<T> que;
     // Sort in lexicographically smallest order
    // priority_queue<T, vector<T>, greater<T>> que;
    for (auto &v : edge) {
        for (auto &u : v) { in[u]++; }
    }
    for (T i = 0; i < in.size(); i++) {
        if (in[i] == 0) que.emplace(i);
    }
    while (!que.empty()) {
        T u = que.front(); // or T u = que.top(); 
        que.pop();
        out.emplace_back(u);
        for (auto &v : edge[u]) {
            in[v]--;
            if (in[v] == 0) que.emplace(v);
        }
    }
    // out.size() != N なら閉路が存在する
    return out;
}
