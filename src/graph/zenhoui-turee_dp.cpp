#include <bits/stdc++.h>
using namespace std;
using Int = long long;

vector<Int> C;

Int dfs(vector<vector<Int>> &edge, vector<Int> &d, int v, int prev = -1) {
    for (auto &next : edge[v]) {
        if (next == prev) continue;
        d[next] = (d[v] + 1);
        dfs(edge, d, next, v);
    }
    return d[v];
}

Int nodeCnt(vector<vector<Int>> &edge, vector<Int> &cnt, int v, int prev = -1) {
    Int res = 1;
    for (auto &next : edge[v]) {
        if (next == prev) continue;
        res += nodeCnt(edge, cnt, next, v);
    }

    return cnt[v] = res;
}

void reRooting(vector<vector<Int>> &edge, vector<Int> &cnt, vector<Int> &dis,
    vector<Int> &d, vector<Int> &ans, int v, int prev, Int val) {
    ans[v] = val + dis[v] * C[v];

    if (prev != -1) { ans[v] -= (d[v] * (cnt[v] - 1) * C[v]); }

    Int N            = edge.size();
    Int childNodeSum = 0;
    Int siblingsSum  = 0;

    for (auto &nv : edge[v]) {
        if (nv == prev) {
            continue;
        } else {
            childNodeSum += cnt[nv];
            siblingsSum += dis[nv] + d[nv];
        }
    }

    for (auto &nv : edge[v]) {
        if (nv == prev) {
            continue;
        } else {
            Int otherChildNode   = childNodeSum - cnt[nv];
            Int otherSibilingSum = siblingsSum - dis[nv] - d[nv];
            otherSibilingSum -= (d[v] * otherChildNode);

            Int valCnt = N - childNodeSum;

            reRooting(edge, cnt, dis, d, ans, nv, v,
                val + valCnt + otherSibilingSum + otherChildNode);
        }
    }
}

Int collectChildDistance(vector<vector<Int>> &edge, vector<Int> &dis,
    vector<Int> &d, int v, int prev) {
    Int res = 0;

    for (auto &nv : edge[v]) {
        if (nv == prev) { continue; }
        res += collectChildDistance(edge, dis, d, nv, v) * C[nv];
    }
    dis[v] = res;
    return dis[v] + d[v] * C[v];
}

int main() {
    Int N;
    cin >> N;

    vector<vector<Int>> edge(N);
    C = vector<Int>(N);
    vector<Int> d(N, 0), cnt(N, 0), dis(N, 0);

    for (int i = 0; i < N - 1; ++i) {
        Int s, t;
        cin >> s >> t;
        --s;
        --t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }
    for (auto &c : C) cin >> c;

    d[0] = 0;

    dfs(edge, d, 0);
    nodeCnt(edge, cnt, 0);
    collectChildDistance(edge, dis, d, 0, -1);

    vector<Int> ans(N);

    reRooting(edge, cnt, dis, d, ans, 0, -1, 0);

    cout << *min_element(ans.begin(), ans.end()) << endl;
}
