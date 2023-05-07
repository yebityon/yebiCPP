#include <bits/stdc++.h>
// c++14なら組み込みのgcdを使ったほう通い
template <class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class U>
U lcm(U m, U n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}
/**
 *拡張ユークリッド互除法
 *ax + by = gcd(a,b)を満たす整数解を求める
 *ax + by = c が整数解を持つための必要十分条件は、cがgcd(a,b)で割り切れることである
 *ax + by = gcd(a,b)の整数解が存在することの一般解は難しいが、とりあえず解ける。
 *see also: https://qiita.com/drken/items/b97ff231e43bce50199a
*/

template <class T>
T _extGCD(T a, T b, T &x, T &y)
{
    if (b == T(0))
    {
        x = T(1);
        y = T(0);
        return a;
    }
    T d = _extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
template <class T>
std::pair<T, T> extGCD(T a, T b)
{
    T x, y;
    _extGCD(a, b, x, y);
    return std::make_pair(x, y);
}

int main()
{
    assert(extGCD(111, 30) == std::make_pair(3, -11));
    std::cout << "OK" << std::endl;
}