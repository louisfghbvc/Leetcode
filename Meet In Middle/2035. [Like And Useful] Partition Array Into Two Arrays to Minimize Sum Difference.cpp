// O(N*(2^N) + (2^N)log(2^N))
// divide two, and combine

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
            vector<int> search1 = second[n-l];
            for(auto &x: search1) x = 2*x;
            sort(search1.begin(), search1.end());
            vector<int> search2 = second[n-l];
            for(auto &x: search2) x = -2*x;
            sort(search2.begin(), search2.end());
            
            for(int x: first[l]){
                int w1 = tot - 2*x, w2 = - tot + 2*x;
                auto p1 = upper_bound(search1.begin(), search1.end(), w1);
                if(p1 != search1.end()) res = min(res, abs(w1 - *p1));
                if(p1 != search1.begin()) res = min(res, abs(w1 - *prev(p1)));
                
                auto p2 = upper_bound(search2.begin(), search2.end(), w2);
                if(p2 != search2.end()) res = min(res, abs(w2 - *p2));
                if(p2 != search2.begin()) res = min(res, abs(w2 - *prev(p2)));
            }
        }
        
        return res;
    }
};
