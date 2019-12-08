#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
#include<bits/stdc++.h>
#include "src/data_structure/lazy_segtree.cpp"



using Int = long long;
using namespace std;
auto Add = [](Int a, Int b ) {return a + b;};
auto Mul = [](Int a, Int b ) {return a * b;};
auto Max = [](Int a, Int b ) {return max(a,b);};
auto Min = [](Int a, Int b ) {return min(a,b);};
auto Left =  [](Int a, Int b) {return a;};
auto Right = [](Int a, Int b) {return b;};
Int e = (1LL << 31) - 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int q; cin >> q;
    ActionMonoid<Int>act(-1,Right,Right,Left);
    foldMonoid<Int>fm(e,Min);
    LazySegtree<Int>lsgt(n,e,fm,act);
    for(int i = 0; i < q; ++i){
        int Q; cin >> Q;
        if(Q == 1){
            int s,t; cin >> s >> t;
            ++t;
            cout << lsgt.query(s,t) << endl;
        } else {
            int s,t,x; cin >> s >> t >> x;
            ++t;
            lsgt.action(s,t,(Int)x);
        }
    }
    return 0;
}

