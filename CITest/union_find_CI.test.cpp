#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
#include "src/data_structure/union-find.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    auto uf = unionfind(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        } else if (com == 1) {
            cout << uf.same(x, y) << endl;
        }
    }
    return 0;
}
