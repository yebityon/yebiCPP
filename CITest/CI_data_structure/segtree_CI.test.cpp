#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include "src/data_structure/seg_tree.cpp"

#include<iostream>
using namespace std;
int main(){
  int N; cin >> N;
  int Q; cin >> Q;
  using Int = long long;
  vector<Int>v(N,0LL);
  Int e = 0LL;
  auto segtree(v,e,[](Int a,INt b){return a + b});
  for(int _ = 0; _ < Q; ++_){
    int com; cin >> com;
    if(com == 0){
      Int x,y; cin >> x >> y;
      sgt.update(--x,sgt[x] + y);
    } else {
      Int x,y; cin >> x >> y;
      cout << sgt.query(--x,y) << endl;
    }
  } 
}
