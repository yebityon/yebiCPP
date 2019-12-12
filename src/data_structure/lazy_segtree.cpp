#include<bits/stdc++.h>
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
template<class T, class Func = function<T(T,T)>>
class LazySegtree{
private:
    const size_t N;
    const ActionMonoid<T> action_monoid;
    const foldMonoid<T> fold_monoid;
    size_t offset;
    vector<T>obj, lazy;
    Func action_updater, lazy_updater;
    /* re-size vectors capacity */
    size_t bufsize(size_t num) {
        int i = 1;
        for (; (int) num + 1 > i; i <<= 1);
        offset = i - 1;
        return (i << 1) - 1;
    }
    void updateall(int l = 0, int r = -1) {
        if (r < 0)r = offset + 1;
        l += offset, r += offset;
        do {
            l = (l - 1) >> 1, r = (r - 1) >> 1;
            for (int i = l; i < r; i++)obj[i] = fold_monoid.f(obj[i * 2 + 1], obj[i * 2 + 2]);
        } while (l);
    }
    /* update k-node*/
    void flush(int k, int l, int r){
        if(lazy[k] == action_monoid.e){
            // There is no vlaue to propagate
        } else {
            obj[k] = action_monoid.g(obj[k],action_monoid.p(lazy[k],r - l));
            // if(r - l <= 1) -> least
            if(r - l > 1) {
                lazy[2 * k + 1] = action_monoid.h( lazy[2 * k + 1],lazy[k]);
                lazy[2 * k + 2] = action_monoid.h( lazy[2 * k + 2],lazy[k]);
            }
            lazy[k] = action_monoid.e;
        }
    }
    void action(int a, int b, T val, int k, int l, int r){
        if (r < 0) r = (int)offset + 1;
        flush(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            // perfectly coverd range
            // TODO := why f???
            lazy[k] = action_monoid.h(lazy[k], val);
            flush(k, l, r);
        } else {
            action(a, b, val, 2 * k + 1, l, (l+r)/2);
            action(a, b, val, 2 * k + 2, (l+r)/2, r);
            obj[k] = fold_monoid.f(obj[2 * k + 1],obj[2 * k + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        flush(k,l,r);
        if (r <= a || b <= l)return fold_monoid.e;
        if (a <= l && r <= b)return obj[k];
        else return fold_monoid.f(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
public:
    void action(int l,int r, T val){
        action(l,r,val,0,0,-1);
    }
    T query(int a, int b) {//[a,b)
        return query(a, b, 0, 0, (int)offset + 1);
    }
    
    LazySegtree(size_t treesize_,T init_, foldMonoid<T>foldM, ActionMonoid<T>ActionM)
    : N(treesize_),fold_monoid(foldM), action_monoid(ActionM)
    {
        obj  = vector<T>(bufsize(N), init_);
        lazy = vector<T>(bufsize(N), action_monoid.e);
        
    }
    LazySegtree(vector<T>&vec, foldMonoid<T>foldM,
    ActionMonoid<T>ActionM)
    : N(vec.size()), fold_monoid(foldM), action_monoid(ActionM)
    {
        obj  = vector<T>(bufsize(N));
        lazy = vector<T>(bufsize(N),action_monoid.e);
        std::copy(vec.begin(),vec.end(),obj.begin() + offset);
        updateall();
    }
    
};

