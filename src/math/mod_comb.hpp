#include<bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;

// 一度だけ計算する用に使う
template <class T> T modpow(T a, T b) {
    if (b == 0) return T(1);
    if (b % 2 == 0) {
        T d = modpow(a, b / T(2));
        return (d * d) % mod;
    } else {
        return (a * modpow(a, b - 1) % mod);
    }
}
template <class T> T mod_nCr(T n, T r, T mod) {
    T denom = 1;
    T numer = 1;
    for (T i = 1; i <= r; i++) numer = (numer * i) % mod;
    for (T i = n - r + 1; i <= n; i++) denom = (denom * i) % mod;
    return (denom * modpow(numer, mod - 2) % mod);
}

template<class T>
class modcomb {
public:
  T maxn, mod;
  vector<T> fac, finv, inv;
  
  modcomb(T _maxn, T _mod)
      : maxn(_maxn), mod(_mod), fac(_maxn), finv(_maxn), inv(_maxn) {
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1]            = 1;
      for (T i = T(2); i < maxn; i++) {
          // iの階乗の逆元
          fac[i] = fac[i - 1] * i % mod;
          // iの逆元
          inv[i] = mod - inv[mod % i] * (mod / i) % mod;
          // iの階乗の逆元
          finv[i] = finv[i - 1] * inv[i] % mod;
      }
    };

    // calcuration of nCk with mod
    T modComb(int n,int k){
        if (n < k) return T(0);
        if (n < 0 || k < 0) return T(0);
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};