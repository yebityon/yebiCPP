#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
#include<bits/stdc++.h>
#include "../../src/data_structure/lazy_segtree.cpp"



using Int = long long;
using namespace std;
auto Add = [](Int a, Int b ) {return a + b;};
auto Mul = [](Int a, Int b ) {return a * b;};
auto Max = [](Int a, Int b ) {return max(a,b);};
auto Min = [](Int a, Int b ) {return min(a,b);};
auto P   = [](Int a, Int b)  {return a * b;};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int q; cin >> q;
    ActionMonoid<Int>act(0LL,Add,Add,Mul);
    foldMonoid<Int>fm(0LL,Add);
    LazySegtree<Int>lsgt(n,0LL,fm,act);
    for(int i = 0; i < q; ++i){
        int Q; cin >> Q;
        if(Q == 1){
            int s,t; cin >> s >> t;
            --s;
            cout << lsgt.query(s,t) << endl;
        } else {
            int s,t,x; cin >> s >> t >> x;
            --s;
            lsgt.action(s,t,(Int)x);
        }
    }
    return 0;
}


