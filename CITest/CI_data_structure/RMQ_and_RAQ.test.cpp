#include<bits/stdc++.h>
#include "src/data_structure/lazy_segtree.cpp"
#define PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
    using namespace std;
    using Int = long long;

    template<class T, class Func = function<T(T,T)>>
    struct foldMonoid{
        T e;
        const Func f;
        foldMonoid(T e_, const Func f_) : e(e_),f(f_){};
    };

    template<class T, class Func = function<T(T,T)>>
    struct ActionMonoid{
        T e;
        const Func g,h,p;
        ActionMonoid(T e_,const Func g_, const Func h_, const Func p_) : e(e_),g(g_), h(h_), p(p_){};
    };
    /*
           g : T × E -> T s.t apply E to T
           h : E × E -> merge E and E
           p : E × N -> p(a,b):= g(a,a,......a ),
                                   |__________|
                                        b
    */
auto Add = [](Int a, Int b ) {return a + b;};
auto Mul = [](Int a, Int b ) {return a * b;};
auto Max = [](Int a, Int b ) {return max(a,b);};
auto Min = [](Int a, Int b ) {return min(a,b);};
auto P   = [](Int a, Int b)  {return a;};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int q; cin >> q;
    ActionMonoid<Int>act(0LL,Add,Add,P);
    foldMonoid<Int>fm(100000000000LL,Min);
    LazySegtree<Int>lsgt(n,0LL,fm,act);
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


