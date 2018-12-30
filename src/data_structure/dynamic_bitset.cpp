class dynamic_bitset {
  private:
    long long bit;
    string sbit                = "";
    unsigned long long bitsize = 0;

  public:
    dynamic_bitset(int _bit) : bit{_bit} {
        for (int t = 1, mask = 2; bitsize == 0; t++, mask *= 2) {
            if (mask - 1 >= bit) bitsize = t;
        }
        for (int i = 0; i < bitsize; i++) {
            sbit = ((bit >> i & 1) == 1 ? "1" : "0") + sbit;
        }
    }
    dynamic_bitset(int _bit, int bitrange) : bit{_bit} {
        for (int t = 1, mask = 2; bitsize == 0; t++, mask *= 2) {
            if (mask - 1 >= bit) bitsize = t;
        }
        for (int i = 0; i < bitrange; i++) {
            sbit = (i < bitsize and ((bit >> i & 1) == 1) ? "1" : "0") + sbit;
        }
    }
    auto test(int _idx) {
        assert(_idx < sbit.size() && "excution will be out of range");
        return sbit[_idx] == '1';
    }
    void set(int _idx) {
        assert(_idx < sbit.size() && "excution will be out of range");
        sbit[_idx] = '1';
    }
    auto size() { return sbit.size(); }
    bool isAll() {
        return accumulate(sbit.begin(), sbit.end(), true,
            [](bool r, char c) { return r && c == '1'; });
    }
    bool none() {
        return accumulate(sbit.begin(), sbit.end(), true,
            [](bool r, char c) { return r && c == '0'; });
    }
    auto to_string() { return sbit; }
};