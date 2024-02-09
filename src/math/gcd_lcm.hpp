#pragma once
#include <bits/stdc++.h>
// c++14なら組み込みのgcdを使ったほうがはやい
template <class T> T mygcd(T a, T b) { return b ? mygcd(b, a % b) : a; }
template <class U> U mylcm(U m, U n) {
    return (0 == m) || (0 == n) ? 0 : (m / mygcd(m, n)) * n;
}

/**
 *拡張ユークリッド互除法
 * ax + by = gcd(a,b)を満たす整数解を求める
 * ax + by = c が整数解を持つための必要十分条件は、cがgcd(a,b)で割り切れることである 
 * ax + by = gcd(a,b)の整数解が存在することの一般解は難しいが、とりあえず解ける。 
 * see also: https://qiita.com/drken/items/b97ff231e43bce50199a
 * @tparam T 型
 * @param a a
 * @param b b
 * @param x x
 * @param y y
 * @return gcd(a,b) 
 */

template <class T> T _extGCD(T a, T b, T &x, T &y) {
    if (b == T(0)) {
        x = T(1);
        y = T(0);
        return a;
    }
    T d = _extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
template <class T> std::pair<T, T> extGCD(T a, T b) {
    T x, y;
    _extGCD(a, b, x, y);
    return std::make_pair(x, y);
}
/**
 * @brief mod 分数の逆元(ax ≡ xa ≡ 1 mod m）となるようなxを求める, aとmが互いに素であることが必要
 * @tparam T 型
 * @param denom 分母
 * @param mod mod
 * @return 分数の逆元
 */
//  実数上の答えが3141/5926の時, invMod(5926, mod) * 3141 % mod で求められる
template < class T> T invMod(T denom, const T mod) {
    T x, y;
    T g = _extGCD(denom, mod, x, y);
    
    if (g != 1) {
        assert(false);
        return -1;
    } else {
        return (x % mod + mod) % mod;
    }
}
