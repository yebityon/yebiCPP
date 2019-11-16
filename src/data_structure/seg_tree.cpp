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
        for (; num + 1 >i; i <<= 1);
        offset = i - 1;
        return (i << 1) - 1;
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return e;
        if (a <= l && r <= b)return obj[k];
        else return updater(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
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
    void update(int k, T &a) {
        k += offset;
        obj[k] = a;
        while (k) {
            k = (k - 1) >> 1;
            obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);
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
};


