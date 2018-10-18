int MOD =INF+7;
ll  doublePower(ll a, ll b ){
    //cal a^b
    if(b==0)return 1;
    if(b%2==0){
        long long d=doublePower(a,b/2);
        return (d*d)%MOD;
    }else{
        return (a*doublePower(a,b-1)%MOD);
    }
}
ll MOD_nCr(ll n,ll r,ll MOD){;
    ll denom=1;
    ll numer=1;
    for(ll i=1;i<=r;i++) numer=(numer*i)%MOD;
    for(ll i=n-r+1;i<=n;i++)denom=(denom*i)%MOD;
    return (denom*doublePower(numer, MOD-2)%MOD);
}
signed main(){
    cout<<MOD_nCr(10,2,MOD)<<endl;
}
