#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr Int inf = (LLONG_MAX >> 1);

/**
 * @brief MexSetを使う前によく考えること
 * 1. すべての入力が1e5の数しかこないとき、最終的な答えは1e5以下であることが多い
 * 2. eraseは自作したメソッドであること
 *
 */
template <typename T> class MexSet {
  private:
    set<pair<T, T>> S;
    const T inf;

  public:
    MexSet(T _inf = 1e9) : inf(_inf) {
        S.emplace(-inf, -inf);
        S.emplace(inf, inf);
    }

    bool contains(T x) {
        const auto itr      = std::prev(S.lower_bound(make_pair(x + 1, x + 1)));
        const auto [lb, ub] = *itr;
        return lb <= x && x <= ub;
    }

    bool insert(T x) {
        if (contains(x)) return true;
        auto itr            = S.lower_bound(make_pair(x + 1, x + 1));
        auto pitr           = std::prev(itr);
        const auto [l, u]   = *itr;
        const auto [pl, pu] = *pitr;

        if (pu + 1 == x && x + 1 == l) {
            /* [6, 9], 10,[11, 15] */
            S.erase(itr);
            S.erase(pitr);
            S.insert(make_pair(pl, u));
        } else if (pu + 1 == x) {
            /* [6, 9], 10, [12, 15] */
            S.erase(itr);
            S.insert(make_pair(pl, x));
        } else if (x + 1 == l) {
            /* [6, 9], 11, [12, 15] */
            S.erase(itr);
            S.insert(make_pair(x, u));
        } else {
            /* [6, 9], 11, [13, 15] */
            S.insert(make_pair(x, x));
        }
        return true;
    }

    bool erase(int x) {
        if (!contains(x)) return false;

        auto nit          = S.lower_bound(std::make_pair(x + 1, x + 1));
        auto it           = prev(nit);
        const auto [l, u] = *it;
        if (l == x && u == x) /* 完全に区間が一致 */ {
            S.erase(it);
        } else if (l == x) {
            int nl = l + 1;
            S.erase(it);
            S.insert(make_pair(nl, u));
        } else if (l < x
                   && x < u) /* ある区間内にxが含まれる場合、下のように分割 */ {
            // [l, x - 1], [x + 1, u]
            S.erase(it);
            S.insert(make_pair(l, x - 1));
            S.insert(make_pair(x + 1, u));
        } else if (x == u) /* 下限が一致するとき */ {
            S.erase(it);
            S.insert(make_pair(l, u - 1));
        } else {
            S.erase(it);
        }
        return true;
    }

    T mex(T x = 0) {
        const auto itr    = S.lower_bound(make_pair(x + 1, x + 1));
        const auto [l, u] = *prev(itr);
        if (l <= x && x <= u) {
            return u + 1;
        } else {
            return x;
        }
    }
};
