#include <bits/stdc++.h>

using namespace std;
//verifyed @https://atcoder.jp/contests/abc106/submissions/4896005
//main(){}

template <class T>
class Cumulative2DSum {
    // query[sx,gx),[sy,gy)
public:
    vector<vector<T>>sum;
    T e;
    Cumulative2DSum(vector<vector<T>>&v,T e) {
        int W = v.size();
        int H = v.front().size();
        ++H , ++W; // why add ????
        sum = vector<vector<T>>(H,vector<T>(W,e));
        
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v[i].size(); ++j){
                sum[i + 1][j + 1] +=  v[i][j];
            }
        }
        for(int i = 1; i < sum.size(); ++i){
            for(int j = 1; j < sum[i].size();++j){
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
    }
    auto query(int sx,int sy,int gx,int gy){
        sum[gx][gy] - sum[sx][gy] - sum[gx][sy] + sum[sx][sy];
    }
};
