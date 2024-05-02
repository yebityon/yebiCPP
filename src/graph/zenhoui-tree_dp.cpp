#include <bits/stdc++.h>
using namespace std;
using Int = long long;

vector<Int> C, dist, csum, cw, ans;
vector<vector<int>> edge;

Int fdist(int v, int prev = -1) {
    for (auto &nv : edge[v]) {
        if (nv == prev) continue;
        dist[nv] = dist[v] + 1;
        fdist(nv, v);
    }
    return dist[v];
}

Int fcsum(int v, int prev = -1) {
    Int sum = 0;
    for (auto &nv : edge[v]) {
        if (nv == prev) continue;
        sum += fcsum(nv, v);
    }
    return csum[v] = sum + C[v];
}

Int fcw(int v, int prev = -1) {
    Int sum = 0;
    for (auto &nv : edge[v]) {
        if (nv == prev) continue;
        sum += fcw(nv, v);
    }
    return cw[v] = sum + dist[v] * C[v];
}

void reRooting(int v, int pv, Int pval = 0) {
    Int pcsum     = csum[0] - csum[v];
    Int childCSum = 0, childCw = 0;
    for (auto nv : edge[v]) {
        if (nv == pv) continue;
        childCSum += csum[nv];
        childCw += cw[nv] - (dist[v] * csum[nv]);
    }
    ans[v] = pval + childCw;

    for (auto nv : edge[v]) {
        if (nv == pv) continue;
        Int nsum = childCSum - csum[nv];
        Int nw   = childCw - (cw[nv] - dist[v] * csum[nv]);
        reRooting(nv, v, pval + pcsum + nw + nsum + C[v]);
    }
}

int main() {
    Int N;
    cin >> N;

    edge = vector<vector<int>>(N);
    C = dist = csum = cw = ans = vector<Int>(N);

    for (int i = 0; i < N - 1; ++i) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }
    for (auto &c : C) cin >> c;

    dist[0] = 0;
    fdist(0);
    fcsum(0);
    fcw(0);
    reRooting(0, -1, 0);

    cout << *min_element(ans.begin(), ans.end()) << endl;
}
