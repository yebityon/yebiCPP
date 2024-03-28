#include <bits/stdc++.h>
using namespace std;
using Int = long long;
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#1-%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%81%A8%E3%81%AF

void example() {
    vector<Int> A = {4, 6, 7, 8, 1, 2, 110, 2, 4, 12, 3, 9};
    int N = A.size(), l = 0, r = 0;
    Int sum = 0, ans = 0, upper_bound(25);
    for (; l < N; ++l) {
        // upper_bound 以下まで r を進める, rが終端に達してもlが進み切るまでスルー
        while (r < N && sum + A[r] <= upper_bound) {
            sum += A[r];
            r++;
        }
        ans += r - l;
        // [l, r) が空(単一要素がupper_boundを超える)の場合はlとrを進める
        if (l == r)
            r++;
        else
            sum -= A[l];
    }
    cout << "区間の長さが25以下の区間の数: " << ans << endl;
}

int main() {
    example();
    return 0;
}
