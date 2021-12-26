// use double is tricky!
// and use module!, easy to code
// O(N)

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long suf = 1, mod = 1e12;
        // use divide 10 can be easy to do that
        // easy to compute how many
        double pre = 1.0; 
        int zero = 0;
        for(int i = left; i <= right; ++i){
            pre *= i;
            while(pre >= 100000)
                pre /= 10;
            suf *= i;
            while(suf % 10 == 0){
                suf /= 10;
                zero++;
            }
            suf %= mod;
        }
        string res = to_string(suf);
        if(res.size() > 10) res = to_string((int)pre) + "..." + res.substr(res.size() - 5);
        return res + "e" + to_string(zero);
    }
};


// use log.
