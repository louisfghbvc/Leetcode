// O(N), Find kth mod num == 0 
class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(!(n%i))
                if(++cnt == k) return i;
        }
        return -1;
    }
};
