#include<bits/stdc++.h>
using namespace std;

template<class T, class Func = function<T(T, T)>>
class segtree {
    vector<T> obj;
    int offset;
    Func updater;
    T e;
    int bufsize(int num) {
        int i = 1;
        for (; num  + 1 > i; i <<= 1);
        offset = i - 1;
        return (i << 1) - 1;
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return e;
        if (a <= l && r <= b)return obj[k];
        else return updater(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
    int find_maximum_index_sub(int a, int b, T x, int k,int l, int r,const Func& f){
        if(!f(obj[k],x) || r <= a || b <= l) return -1;
        if(k >= offset) return k - offset;
        /* search * right *  subtree to find x*/
        int rv = find_maximum_index_sub(a,b,x,2 * k + 2, (l + r) / 2,r,f);
        if(rv  !=  -1) return rv;
        /* find maximum ( right ) index, so that left subtree will be searched only if  there is no elem in right subtree*/
        return find_maximum_index_sub(a,b,x, 2 * k + 1, l, (l + r) / 2,f);
    }
    int find_minimum_index_sub(int a, int b, T x, int k, int l, int r,const Func& f){
        if(!f(obj[k],x) || r <= a || b <= l) return -1;
        if(k >= offset) return k - offset;
        /* search * right *  subtree to find x*/
        int lv = find_minimum_index_sub(a,b,x, 2 * k + 1, l, (l + r) / 2,f);
        if(lv  !=  -1) return lv;
        /* find maximum ( right ) index, so that left subtree will be searched only if  there is no elem in right subtree*/
        return find_minimum_index_sub(a,b,x,2 * k + 2, (l + r) / 2,r,f);
    }
public:
    T query(int a, int b) {//[a,b)
        return query(a, b, 0, 0, offset + 1);
    }
    void updateall(int l = 0, int r = -1) {
        if (r < 0)r = offset + 1;
        l += offset, r += offset;
        do {
            l = (l - 1) >> 1, r = (r - 1) >> 1;
            for (int i = l; i < r; i++)obj[i] = updater(obj[i * 2 + 1], obj[i * 2 + 2]);
        } while (l);
    }
    void update(int k, T a) {
        k += offset;
        obj[k] = a;
        while (k) {
            k = (k - 1) >> 1;
            obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);
        }
    }
    //[l,r)
    int find_maximum_index(int l, int r, T x,const Func& f) {
        return find_maximum_index_sub(l,r,x,0,0,offset + 1,f);
    }
    // (l,r]
    int find_minimum_index(int l, int r, T x,const Func& f){
        return find_minimum_index_sub(l,r,x,0,0,offset + 1,f);
    }
    void print_tree(){
        int id = 0;
        int sum = obj.size();
        for(int i = 0;sum > 0 ; ++i){
            for(int j = 0; j < (1 << i); ++j){
                cout << obj[id++] << " ";
                --sum;
            }
            cout << endl;
        }
    }
    
    segtree(int n, T e, const Func &updater = Func()) :obj(bufsize(n), e), e(e), updater(updater) {}
    segtree(vector<T> &vec, T e, const Func &updater = Func()) :obj(bufsize(vec.size()), e), e(e), updater(updater) {
        copy(vec.begin(), vec.end(), obj.begin() + offset);
        updateall();
    }
    typename vector<T>::reference operator[](int n) {
        return obj[n + offset];
    }
    void set(int id, T x){
        update(id,x);
    }
};
