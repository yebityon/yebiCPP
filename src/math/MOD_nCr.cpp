constexpr int MOD = 1e9 + 7;
template <class T> T modpow(T a, T b) {
    if (b == 0) return T(1);
    if (b % 2 == 0) {
        long long d = modpow(a, b / T(2));
        return (d * d) % MOD;
    } else {
        return (a * modpow(a, b - 1) % MOD);
    }
}
template<class T> T mod_nCr(T n, T r, T MOD) {
    T denom = 1;
    T numer = 1;
    for (ll i = 1; i <= r; i++) numer = (numer * i) % MOD;
    for (ll i = n - r + 1; i <= n; i++) denom = (denom * i) % MOD;
    return (denom * modpow(numer, MOD - 2) % MOD);
}
signed main() { cout << mod_nCr(10, 2, MOD) << endl; }
