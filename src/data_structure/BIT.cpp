int bit [1000] = {},n;

//[1,n]
//get sum from [i,n]
int sum(int i){
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
// add a_i += x
void add (int i,int x){
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}i
