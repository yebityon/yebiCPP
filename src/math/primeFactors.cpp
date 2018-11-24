vector<int> primeFactors(int n) {
    vector<int> v;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            v.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    if(n != 1)v.push_back(n);
    return v;
}
