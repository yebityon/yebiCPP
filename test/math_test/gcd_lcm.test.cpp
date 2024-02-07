# include "../../src/math/gcd_lcm.hpp"

int main()
{
    int a = 12;
    int b = 18;
    assert(mygcd(a, b) == 6);
    assert(mylcm(a, b) == 36);
}
