// Simple O(nloglogn)
class Solution {
public:
    bool np[5000001];
    int countPrimes(int n) {
        int cnt = 0;
        for(int i = 2; i < n; ++i){
            if(!np[i]){
                cnt++;
                for(int j = 2*i; j < n; j+=i)
                    np[j] = 1;
            }
        }
        return cnt;
    }
};
