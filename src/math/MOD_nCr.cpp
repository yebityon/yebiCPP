#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
template <class T> T modpow(T a, T b) {
    if (b == 0) return T(1);
    if (b % 2 == 0) {
        long long d = modpow(a, b / T(2));
        return (d * d) % mod;
    } else {
        return (a * modpow(a, b - 1) % mod );
    }
}
template<class T> T mod_nCr(T n, T r, T mod ) {
    T denom = 1;
    T numer = 1;
    for (T i = 1; i <= r; i++) numer = (numer * i) % mod;
    for (T i = n - r + 1; i <= n; i++) denom = (denom * i) % mod;
    return (denom * modpow(numer, mod - 2) % mod);
}
signed main() { cout << mod_nCr(10, 2, mod) << endl; }
