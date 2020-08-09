// O(n2^n). simulate.
// 784ms.
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        string ns;
        for(int i = 1; i < n; ++i){
            ns = s;
            ns += '1';
            for(int k = s.size()-1; k >= 0; --k){
                ns += s[k]=='0' ? '1' : '0';
            }
            s = ns;
        }
        return s[k-1];
    }
};

// Recursive
// 0ms.
// if k-1 == len/2 must '1'
// or if left side or right side.
// right side reverse bit and backward.
class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1<<n)-1;
        if(n == 1) return '0';
        if(k-1 == len/2) return '1';
        if(k-1 < len/2) return findKthBit(n-1, k);
        return findKthBit(n-1, len-k+1) == '0' ? '1' : '0';
    }
};
