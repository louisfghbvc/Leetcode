// O(N). cause it will get corner. so just simulate. 
// and finally if dir = true, means wall in right. otherwise wall in left.

class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(!q) return 0;
        if(p == q) return 1;
        bool dir = 1;
        int pos = q;
        for(; pos % p != 0; pos += q) dir ^= 1;
        if(!dir) return 2;
        return (pos/p)%2;
    }
};

// gcd.
