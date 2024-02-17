#include "../../src/math/mod_comb.hpp"
#include <cassert>
// verify here : https://atcoder.jp/contests/abc145/submissions/8684423

int main()
{
    //generet test
    constexpr long long mod = 1e9 + 7;
    modcomb<long long> mc(1000000LL, mod);
    for (long long i = 10000; i < 1000000LL; i+= 100) {
        for (long long j = 0; j < 100; j++)
        {
            assert(mc.modComb(i, j) == mod_nCr(i, j, mod));
        }
    }
    std::cout << "modcomb test passed" << std::endl;
}