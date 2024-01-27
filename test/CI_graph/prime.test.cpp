#include<bits/stdc++.h>
using namespace std;
#include"../../src/graph/prim.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#define IGNORE
using pii = pair<int,long long>;

int main(){
    int v,e; cin >> v >> e;
    vector<vector<pii>>t(v);
    for(int i = 0; i < e; ++i){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        t[a].emplace_back(b,c);
        t[b].emplace_back(a,c);
    }
    Prim<long long> p(t);
    cout << p.getval() << endl;
}
