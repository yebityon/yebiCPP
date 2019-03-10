#include <bits/stdc++.h>
using namespace std;
template<class T>
class dynamic_bitset {
private:
    T bit_num;
    string bit_string               = "";
    unsigned int bit_size = 0;
    vector<bool>bit_vector; //[0,bit_size)
    // dynamic_bitset(8) should be :1000
    
public:
    dynamic_bitset(T bit) : bit_num{bit} {
        for (T t = T(1), mask = T(2); bit_size == 0; t++, mask *= T(2)) {
            if (mask - T(1) >= bit) bit_size = (unsigned int)t;
        }
        bit_vector = vector<bool>(bit_size,false);
        for (T i = T(0); i < bit_size; i++) {
            bit_string = ((bit >> i & T(1)) == T(1) ? "1" : "0") + bit_string;
            bit_vector[bit_size - 1 - i] = (bit >> i & T(1));
        }
    }
    dynamic_bitset(T bit, int bit_range) : bit_num{bit} {
        for (T t = T(1), mask = T(2); bit_size == 0; t++, mask *= T(2)) {
            if (mask - 1 >= bit) bit_size = (unsigned int)t;
        }
        bit_vector = vector<bool>(bit_range,false);
        assert(bit_range  >=  bit_size and "out of range");
        for (int i = 0; i < bit_range; i++) {
            bit_string = (i < bit_size and ((bit >> i & T(1)) == 1) ? "1" : "0") + bit_string;
        }
        for(int i = 0; i < bit_size;++i){
            bit_vector[bit_range - bit_size + bit_size - 1 -i] = (bit >> i & 1);
        }
    }
    auto test(int idx) {
        assert(idx < bit_string.size() && "excution will be out of range");
        return bit_vector[idx];
    }
    void set(int idx) {
        assert(idx < bit_string.size() && "excution will be out of range");
        bit_string[idx] = '1';
        bit_vector[idx] = true;;
    }
    auto size() { return bit_vector.size(); }
    bool isAll() {
        return accumulate(bit_vector.begin(), bit_vector.end(), true,[](bool r, bool e) { return r and e; });
    }
    bool none() {
        return accumulate(bit_vector.begin(), bit_vector.end(), true,[](bool r, bool e) { return r and e; });
    }
    auto to_string() { return bit_string; }
    auto to_vector() { return bit_vector; }
    auto stoi(string bit_str){
        T res = 0;
        for(int i = (int)bit_str.size() - 1; i >= 0;--i){
            if(bit_str[i] == '1'){
                res += (1LL << ((int)bit_str.size() - 1 - i));
            }
        }
        return res;
    }
    auto vtoi(vector<bool>v){
        T res =T(0);
        for(int i = (int)v.size() - 1; i >= 0;--i){
            res += (v[i] ? T(1) << ((int)v.size() -1 - i) : T(0));
        }
        return res;
    }
};

int main(){
}


