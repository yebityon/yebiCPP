#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr Int inf = (LLONG_MAX >> 1);

template <typename T> class mex_set {
  private:
    set<pair<T, T>> S;

  public:
    bool insert(T x) { return false; }
    bool contain(T x) { return false; }
    bool erase(int x) {
        auto nit          = s.lower_bound(std::make_pair(x + 1, x + 1));
        auto it           = prev(nit);
        const auto [l, u] = *it;
        // 完全一致
        if (l == x && u == x) {
            s.erase(it);
        } else if (l == x) {
            int nl = l + 1;
            s.erase(it);
            s.insert(make_pair(nl, u));
        } else if (l < x && x + 1 <= u) {
            // [l, x - 1], [x + 1, u)
            s.erase(it);
            s.insert(make_pair(l, x - 1));
            s.insert(make_pair(x + 1, u));

        } else if (x == u) {
            s.erase(it);
            s.insert(make_pair(l, u - 1));
        } else {
            s.erase(it);
        }
        return true;
    }
    T mex(T x) { return T(0); }
};
