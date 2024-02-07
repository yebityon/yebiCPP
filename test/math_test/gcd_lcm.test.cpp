
#include "../../src/math/gcd_lcm.hpp"
#include <cassert>

int main() {
    assert(mygcd(54, 24) == 6);
    assert(mygcd(101, 103) == 1);

    assert(mylcm(5, 3) == 15);
    assert(mylcm(7, 11) == 77);

    auto res = extGCD(6, 15);
    assert(res.first * 6 + res.second * 15 == mygcd(6, 15));

    assert(invMod(3, 7) == 5);  // Because (3*5) % 7 = 1
    assert(invMod(10, 17) == 12);
    
    long long a = 123456789LL;
    long long b = 987654321LL;

    long long gcd = mygcd(a, b);
    std::cout << "gcd(" << a << ", " << b << ") = " << gcd << std::endl;
    assert(gcd == mygcd(b, a));

    long long lcm = mylcm(a, b);
    std::cout << "lcm(" << a << ", " << b << ") = " << lcm << std::endl;
    assert(lcm == mylcm(b, a));

    res = extGCD(a, b);
    std::cout << "extGCD(" << a << ", " << b << ") = (" << res.first << ", "
              << res.second << ")" << std::endl;
    assert(res.first * a + res.second * b == std::__gcd(a, b ));

    long long mod = 1e9 + 7;
    long long inv = invMod(a, mod);
    std::cout << "invMod(" << a << ", " << mod << ") = " << inv << std::endl;
    assert((inv * a) % mod == 1);

    mod = 998244353;
    for(long long i = 181929931LL; i < 181929931LL + 100LL; i++) {
        long long inv = invMod(i, mod);
        std::cout << "invMod(" << i << ", " << mod << ") = " << inv << std::endl;
        assert((inv * i) % mod == 1);
    }
}