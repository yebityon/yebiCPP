#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
constexpr int INF = (numeric_limits<int>::max() == INT_MAX ? (int)1e9 : (long long)1e18);
constexpr long double eps = 1e-6;
const string el = "\n";
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;using pii = pair<int,int>;using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
void fast_io(){ios::sync_with_stdio(false); cin.tie(nullptr);}
int out(int a){cout << a << el; return 0;}
int out(string s = "NO"){cout << s << el; return 0;}
template <class T>
inline int out(vector<T>&v,string c = " "){
    for(int i = 0; i < v.size(); ++i){
        if(i) cout << c; cout << v[i];
    } cout << el;return 0;
}
