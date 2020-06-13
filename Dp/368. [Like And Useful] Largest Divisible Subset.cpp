// O(N^2)
// can observe, 1 2 4 8, or 4 8 240.
// u can see the i, and j(>i). must incresing order mod.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> lis(n, 1);
        vector<int> pre(n, -1);
        int mx = 0, ind = -1;
        for(int i = 0; i < n; ++i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] % nums[j] == 0){
                    if(lis[i] < lis[j]+1){
                        lis[i] = lis[j]+1;
                        pre[i] = j;
                    }
                }
            }
            if(mx < lis[i]){
                mx = lis[i];
                ind = i;
            }
        }
        vector<int> res;
        for(; ind != -1; ind = pre[ind]){
            res.push_back(nums[ind]);
        }
        
        return res;
    }
};
