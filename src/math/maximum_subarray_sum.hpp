#include <bits/stdc++.h>
using namespace std;

// verified https://atcoder.jp/contests/arc174/submissions/53730045

/**
 * @brief Aの連続部分列の最大和を求める。
 */
template <class T> T MaximumSubrraySum(vector<T> &A, T e = 0) {
    T m   = e;
    T s   = e;
    T res = e;
    for (auto &a : A) {
        s += a;
        m   = min(m, s);
        res = max(res, s - m);
    }
    return res;
}

template <typename T> T MinimumSubrraySum(vector<T> &A, T e = 0) {
    T m   = e;
    T s   = e;
    T res = e;
    for (auto &a : A) {
        s += a;
        m   = max(m, s);
        res = min(res, s - m);
    }
    return res;
}
