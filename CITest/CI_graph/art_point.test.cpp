#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
#include<bits/stdc++.h>
using namespace std;
#include "../../src/graph/art_point.cpp"

signed main(){
    int N,m;
    cin >> N >> m;
    vector<vector<int>>edge;
    edge.resize(N);
    for(int i = 0;i < m; i++){
        int s,t;
        cin >> s >> t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }
    auto ap = art_point(N,edge);
    ap.show_art_point();
}
