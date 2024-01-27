#define PROBLEM https://codeforces.com/contest/1265/problem/C

#include "../../src/data_structure/CumulativeSum.cpp"

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
/*
 (imin,imax] -> imax
 return minimum index such that v[index] >= value
 auto f(int mid) {return v[mid] >= value;}
 */
template<class F, class T>
auto  minimize(T imin,T imax,F &f){
    while(imax - imin > 1){
        T mid = imin + (imax - imin)/2;
        if(f(mid)) imax = mid;
        else imin = mid;
    }
    return imax;
}

/*
 [imin,imax) -> imin
 return maximum index such that v[index] <= value
 auto f(int mid) {return v[mid] <= value;}
 */
template<class F,class T>
auto  maximize(T imin,T imax,F &f){
    while(imax - imin > 1){
        T mid = imin + (imax - imin)/2;
        if(f(mid)) imin = mid;
        else imax = mid;
    }
    return imin;
}
signed main(){
    int t; cin >> t;
    rep(i,t){
        int N; cin >> N;
        vector<int>v(N);
        for(auto& e : v) cin >> e;
        map<int,int,greater<>>mp;
        map<int, int>idx;
        for(auto e : v) mp[e]++;
        vector<int>cnt(mp.size());
        int id = 0;
        for(auto itr : mp){
            cnt[id] = itr.second;++id;
        }
        auto csum = CumulativeSum<int>(cnt,0LL);
        int end = 0;
        for(auto e : csum.sum){
            end++;
            if(e > N /2) break;
        }
        --end;
        int sidx = (upper_bound(csum.begin(),csum.end(), csum[0] + csum[0]) - csum.begin()) + 1;
       // cout << "sidx " << sidx << endl;
        if(sidx == 0 or sidx >= end or
           csum[0] >= csum.query(1,sidx) or csum[0] >= csum.query(sidx,end)){
            cout << "0 0 0" << endl;
        } else {
            cout << csum[0] << " ";
            cout << csum.query(1,sidx) << " ";
            cout << csum.query(sidx, end) << endl;
        }
    }
}

