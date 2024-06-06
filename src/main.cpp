#include <bits/stdc++.h>
using namespace std;

int main() {
    using Int         = long long;
    constexpr Int mod = 998244353;

    Int N;
    cin >> N;
    vector<Int> A(N);
    for (auto &e : A) cin >> e;

    map<int, int> cnt;
    for (auto e : A) {
        auto s = to_string(e);
        cnt[s.length()] += 1;
    }
    Int ans = 0;
    Int tmp = 0;
    for (auto e : A) {
        cnt[to_string(e).length()] -= 1;
        for (auto itr : cnt) {
            if (itr.second == 0) continue;
            Int p = powl(10LL, itr.first) * itr.second;
            p %= mod;
            ans += p * e;
            ans %= mod;
        }
        ans += e * tmp;
        ans %= mod;
        tmp++;
    }
    cout << ans << endl;
}
