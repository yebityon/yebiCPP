#include<bits/stdc++.h>
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
#include "../../src/graph/Minimum_cost_flow.cpp"

using namespace std;
using Int = long long;
int main(){
    int V,E,F; cin >> V >> E >> F;
    auto mcf = MCF<Int>(V + 1);
    for(int i = 0; i < E; ++i){
        int u,v,c,d;
        cin >> u >> v >> c >> d;
        mcf.add_edge(u,v,c,d);
    }
    Int f = mcf.min_cost_flow(0,V - 1,F);
    cout << f << endl;
}
