#include<bits/stdc++.h>
using namespace std;

template<class T>
class modcomb {
public:

    modcompb(T _maxn, T _mod):maxn(_maxn),mod(_mod),fac(_maxn),finv(_maxn),inv(_maxn){
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (T i = T(2); i < maxn; i++){
            // iの階乗の逆元
            fac[i] = fac[i - 1] * i % mod;
            // iの逆元
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            // iの階乗の逆元
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    };
    
    T maxn,mod;
    vector<T>fac,finv,inv;

    // calcuration of nCk with mod
    T modComb(int n,int k){
        if (n < k) return T(0);
        if (n < 0 || k < 0) return T(0);
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};