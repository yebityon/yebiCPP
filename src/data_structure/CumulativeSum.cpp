template <class T>
class CumulativeSum{
public:
    vector<T>sum;
    T e;
    
    CumulativeSum(vector<T>v,T e) : sum(v.size()),e(e){
        copy(v.begin(),v.end(),sum.begin());
        T past = 0;
        for(auto && itr : sum){
            itr += past;
            past = itr;
        }
    }
    //[l,r)
    auto getsum(int l, int r){
        if(r > 0) return (sum[r - 1] - (l == 0 ? 0 : sum[l - 1]));
        else return e;
        
    }
};
