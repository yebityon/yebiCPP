#includ <bits/stdc++.h>
using namespace std;

template<class T, class Func = function<T(T,T)>>
class CumulativeSum{
public:
    vector<T>sum;
    T e;
    CumulativeSum(const vector<T>v,T e,const Func& f = [](T a, T b){return a + b;}) : sum(v.size()),e(e){
        copy(v.begin(),v.end(),sum.begin());
        T past = 0;
        for(auto & itr : sum){
            itr = f(itr,past);
            past = itr;
        }
    }
    //[l,r)
    auto query(int l, int r, const Func& f = [](T a,T b){return a - b;}){
        if(r > 0) return f(sum[r - 1],(l == 0 ? e : sum[l - 1]));
        else return e;
        
    }
    auto begin(){
        return sum.begin();
    }
    auto end(){
        return sum.end();
    }
    auto& operator[] (int idx){
        return sum[idx];
    }
};
