// O(N*(2^N) + (2^N)log(2^N))
// divide two, and combine, abs only consider b = (tot - 2*a)/2

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n >>= 1;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        
        // enum first half, and second half
        vector<vector<int>> first(n+1), second(n+1);
        for(int i = 0; i < 1<<n; ++i){
            int val = 0;
            for(int j = 0; j < n; ++j){
                if(i >> j & 1) val += nums[j];
            }
            first[__builtin_popcount(i)].push_back(val);
        }
        for(int i = 0; i < 1<<n; ++i){
            int val = 0;
            for(int j = 0; j < n; ++j){
                if(i >> j & 1) val += nums[j+n];
            }
            second[__builtin_popcount(i)].push_back(val);
        }
        
        //  dif = |tot - (a+b) - (a+b)| = |tot - 2*(a+b)|
        //  ans => tot - (2a + 2b) = (tot - 2a) ~ 2b
        //  ans => -tot + (2a + 2b) = (-tot + 2a) ~ -2b
        //  enumerate all possible
        int res = INT_MAX;
        for(int l = 0; l <= n; ++l){
            sort(second[n-l].begin(), second[n-l].end());
            auto &search = second[n-l];
            for(int x: first[l]){
                int b = (tot - 2*x) / 2;
                auto p1 = upper_bound(search.begin(), search.end(), b);
                if(p1 != search.end()) res = min(res, abs(tot - 2*(x+*p1)));
                if(p1 != search.begin()) res = min(res, abs(tot - 2*(x+*prev(p1))));
            }
        }
        
        return res;
    }
};
