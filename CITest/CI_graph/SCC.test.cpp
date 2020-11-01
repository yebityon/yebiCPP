#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include<bits/stdc++.h>
#include "../../src/graph/SCC.cpp"
using namespace std;
using Int = long long;
int main(){
	  std::ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
    int N,E;
    cin >> N >> E;
    vector<vector<int>>v(N);
    for(int i = 0; i < E; ++i){
        int s,t; cin >> s >> t;
        v[s].push_back(t);
    }
    StronglyConnectedComponents<int>scc(v);
    scc.build();
    int Q;
    cin >> Q;
    while(Q--){
        int a,b; cin >> a >> b;
        cout  << (scc.isSamePointSet(a,b) ? "1" : "0") << endl;
    }
}
