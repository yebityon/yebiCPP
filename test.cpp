#include <bits/stdc++.h>
using ll = long long;
#define int ll
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, s, n) for (int i = s; i < n; i++)
#define erep(e, v) for (auto &&e : v)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? (int) 1e9 : (int) 1e18)
#define EPS 0.0000000001
using namespace std;
template <class T, class S> auto cmin(T &a, const S &b) {
    return (a > b ? a = b, true : false);
}
template <class T, class S> auto cmax(T &a, const S &b) {
    return (a < b ? a = b, true : false);
}
template <typename Head, typename Value>
auto vectors(const Head &head, const Value &v) {
    return vector<Value>(head, v);
}
template <typename Head, typename... Tail> auto vectors(Head x, Tail... tail) {
    auto inner = vectors(tail...);
    return vector<decltype(inner)>(x, inner);
}
template <class T> void join(T a) {
    for (auto itr : a) {
        if (itr != *a.begin()) cout << " ";
        cout << itr;
    }
}
using ld   = long double;
using pii  = pair<int, int>;
using piii = pair<int, pii>;
int W, H;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool valid(int x, int y) { return (0 <= x && x < W) && (0 <= y && y < H); }
main() {
    int n, m;
    while (cin >> n >> m, n + m) {
        map<int, int> mp;
        rep(i, n) {
            int d, v;
            cin >> d >> v;
            cmax(mp[d], v);
        }
        int ans = 0;
        for (auto itr : mp) ans += itr.second;
        cout << ans << endl;
    }
}