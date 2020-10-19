// mod inverse.
// so just use two extra param, so that no need to mul or add all array.
// just adjust the input by (val - add ) / mul
// so how to convert / mul. use 費馬定理.
// impressive.
// avg O(1)

class Fancy {
public:
    const int mod = 1e9+7;
    
    vector<int> arr;
    long add = 0;
    long mul = 1;
    
    Fancy() {
        
    }
    
    int fpow(long x, int y){
        int res = 1;
        while(y){
            if(y&1) res = (long)res*x%mod;
            x = (long)x*x%mod;
            y >>= 1;
        }
        return res;
    }
    
    void append(int val) {
        val = ((long)val - add + mod) % mod * fpow(mul, mod-2) % mod;
        arr.push_back(val);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (((long)arr[idx] * mul) % mod + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
