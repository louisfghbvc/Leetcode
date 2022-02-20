// gcd is so smart!!
// O(n*factors(k))

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        // nums[i] * nums[j] % k == 0
        
        unordered_map<int, long> fac;
        for(int i = 1; i*i <= k; ++i){
            if(k % i == 0){
                fac[i] = 0;
                if(k / i != i)
                    fac[k / i] = 0;
            }
        }
        
        long res = 0;
        for(int x: nums){
            int need = k / __gcd(x, k);            
            res += fac[need];
            
            // update map
            for(auto &[a, b]: fac){
                if(x % a == 0)
                    b++;
            }
        }
        
        return res;
    }
};
