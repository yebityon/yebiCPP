//  verifyd @https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/3982357/yebityon/C++14
//
//
#include<bits/stdc++.h>
using namespace std;
#include"../../src/data_structure/union-find.hpp"
template<class T>
T Kruskal(const vector<vector<pair<T,T>>>&edge){
  T res = 0;
  using tp = tuple<T,T,T>;
  vector<tp>g;
  for(T i = 0; i < edge.size(); ++i){
    for(auto p : edge[i]){
      T j,cost;
      tie(j,cost) = p;
      g.emplace_back(cost,i,j);
    }
  }
  sort(g.begin(),g.end());
  auto uf =  unionfind(edge.size() + 1);
  for(auto tup : g){
    T cost,s,t;
    tie(cost,s,t) = tup;
    if(uf.same(s,t))continue;
    uf.unite(s,t);
    res += cost;
  }
  return res;
}
