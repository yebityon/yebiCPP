#include <bits/stdc++.h>
//@verifyed
template<class T> T gcd(T a,  T b) {return b ? gcd(b, a % b) : a;}
template<class U> U lcm( U m, U n ){if((0 == m )||( 0 == n ))return 0; return ((m / gcd(m, n)) * n); }

//main(){}
//
