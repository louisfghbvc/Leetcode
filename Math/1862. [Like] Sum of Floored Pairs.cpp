// Build array tour. like sieve.
// O(NlogN).

class Solution {
public:
    const int mod = 1e9+7;
    
    long bit[100005] = {};
    const int N = 1e5;
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        
        long res = 0;
        
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        
        for(auto &[k, v]: mp){
            for(int j = k, base = 1; j <= N; j += k, base++){
                bit[j] += base*v;
                if(j + k <= N)
                    bit[j + k] -= base*v;
            }
        }
        
        for(int i = 1; i <= 100000; ++i)
            bit[i] += bit[i-1];
        
        for(int x: nums)
            res += bit[x], res %= mod;
        
        return res;
    }
};

