#include<bits/stdc++.h>
using namespace std;
const string el = "\n";
inline int out(int a){cout << a << el; return 0;}
inline int out(string s = "NO"){cout << s << el; return 0;}
inline int out(long double a){std::cout << setprecision(10) << fixed << a << endl; return 0;}
template<class T>
inline int out(vector<T>&v,string c = " "){
    for(int i = 0; i < v.size(); ++i){
        if(i) cout << c; cout << v[i];
    } cout << el;return 0;
}

long double fH(vector<long double>&v){
    long double res = 0;
    int sum = accumulate(v.begin(),v.end(),0);
    out(sum);
    long double loge = 1; long double pall = 1;
    for(const auto e : v){
        if(e == 0)continue;
        long double p = e / (long double)sum;
        res -= (p * log2(p));
        loge *= p; pall *= p;
    }
    return res;
}
signed main(){
    vector<int>p;
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist(1,6);
    for(int i = 0; i < 128; ++i)p.emplace_back(dist(engine) % 2);
    for(int i = 0; i < 128; i += 4){
        for(int j = 0; j < 4; ++j)
            cout << p[i + j];
        cout << endl;
    }
    const string befo = "11000000011011110011101010001100001111110101001111000110111001100000001010000001011101111111101100001011000011110011110000111111";
    for(auto c : p) cout << c;
    cout << endl;
    vector<long double>two(2,0);
    vector<long double>four(4,0);
    vector<long double>eight(16,0);
    for(auto e : p)two[e] += 1;
    for(int i = 0; i + 1 < p.size(); i += 2){
        int cal = 0;
        for(int j = 0; j < 2; ++j){
            int idx = i + j;
            cal += (p[idx] << (1 - j));
        }
        four[cal]  += 1;
    }
    vector<int>check;
    for(int i = 0; i + 3 < p.size(); i += 4){
        int cal = 0;
        for(int j = 0; j < 4; ++j){
            int idx = i + j;
            cal += (p[idx] << (3 - j));
            check.emplace_back(p[idx]);
        }
        eight[cal] += 1;
    }
    assert(check == p);
    out(two); out(el);
    out(four); out(el);
    out(eight); out(el);
    //entropy
    out("two : " + to_string(fH(two)));
    out("four : " + to_string(fH(four)));
    out("eight : " + to_string(fH(eight)));
    
}




#include<bits/stdc++.h>
int  filter(int crt, double rate){
    int res =  (crt * (1 - rate/100));
    if(res % 10 >= 5) res += 10 - res % 10;
    else res -= res % 10;
    return res;
}
int main(){
    while(true){
        //[0,9999999], [0,50]
        //無効同値:(-1,x,0) (1,000,000,0,x,0), (x,-1,0),(x,51,0)
        //dについて (1500,0,500), (2101,25,600) (2100,25,530)
        //rについて (3000,50,500),(3000,0,3000),(1800,26,440), (1801,25,530)
        int d,r; std::cin >> d >> r;
        if(d <= 1500){
            std::cout << filter(500,r) << std::endl;
        } else {
            int dif = d - 1500;
            std::cout << filter(500 + 100 * (dif / 300  + (dif % 300 != 0)), r)
            << std::endl;
        }
    }
}

