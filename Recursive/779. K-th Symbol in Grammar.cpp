// 4 lines. trick. observe. odd is same as parent.
// even is change from parent.

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        if(K & 1)
            return kthGrammar(N-1, (K+1)/2);
        return (kthGrammar(N-1, K/2))^1;
    }
};
