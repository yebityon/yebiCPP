#include <bits/stdc++.h>
using namespace std;
using Int = long long;

void diameter_dfs(
    int v, int p, vector<vector<pair<int, Int>>> &edge, vector<Int> &dist) {
    for (const auto [nv, cst] : edge[v]) {
        if (nv == p) continue;
        dist[nv] = dist[v] + cst;
        diameter_dfs(nv, v, edge, dist);
    }
}

/**
 * @brief 木の直径を求める, 2回DFSを行う
 */
Int diameter(vector<vector<pair<int, Int>>> &edge, int sv = 0) {
    const int N = edge.size();
    vector<Int> dist(N, 0LL);
    diameter_dfs(sv, -1, edge, dist);
    int far_sv = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(N, 0LL);
    diameter_dfs(far_sv, -1, edge, dist);
    return *max_element(dist.begin(), dist.end());
}

// verify: https://atcoder.jp/contests/abc361/submissions/55322150
// グラフが木のとき、すべての頂点を1度以上訪れるための最短距離の最小値は2 *
// (全辺の重みの総和) - (木の直径) proof:
// 各辺について、その辺を取り除くことができる2つの連結成分の間の行き来を考えると、各辺を2回通る必要がある。よって、2
// * (全辺の重みの総和)が下界となる。
// 求めるものは、各頂点を1度以上訪れるための最短距離の最小値であり、終点から始点への移動距離の最大値は木の直径に等しいから、これを引けばよい
int main() {
    int N;
    cin >> N;
    Int csum = 0;
    vector<vector<pair<int, Int>>> edge(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        Int c;
        cin >> a >> b >> c;
        --a, --b;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
        csum += c;
    }
    Int p = diameter(edge);
    cout << 2 * csum - p << endl;
}
