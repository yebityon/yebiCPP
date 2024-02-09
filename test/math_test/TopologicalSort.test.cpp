#include <bits/stdc++.h>
using namespace std;
#include "../../src/math/TopologicalSort.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B"

int out(int a){cout << a << endl; return 0;}
int out(string s = "NO"){cout << s << endl; return 0;}

template <class T>
inline int out(vector<T>&v,string c = " "){
    for(int i = 0; i < v.size(); ++i){
        if(i) cout << c; cout << v[i];
    } cout << endl;return 0;
}
void yebi(){
    int N,Q;
    cin >> N >> Q;
    vector<vector<int>>edge(N);
    for(int i = 0; i < Q; ++i){
        int s,t; cin >> s >> t;
        edge[s].push_back(t);
    }
    vector<int>order;
    for(auto v : TopologicalSort(edge)){
        order.push_back(v);
    }
    out(order,"\n");
}
signed main(){
    int Q = 1;
    yebi(); return 0;
}


