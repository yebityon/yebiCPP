class modcomb {
public:
    int maxn,MOD;
    vector<int>fac,finv,inv;
    modcomb(int _maxn,int _mod) : maxn(_maxn),MOD(_mod),fac(_maxn),finv(_maxn),inv(_maxn){
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < maxn; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    };
    int modComb(int n,int k){
        if (n < k) return 0LL;
        if (n < 0 || k < 0) return 0LL;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
    
};