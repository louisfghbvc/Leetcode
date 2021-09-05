// Simliar to 4 sum, can use hashtable to speed up.
// O(N^4)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int a = 0; a < n; ++a)
            for(int b = a+1; b < n; ++b)
                for(int c = b+1; c < n; ++c)
                    for(int d = c+1; d < n; ++d)
                        cnt += nums[a]+nums[b]+nums[c] == nums[d];
        return cnt;
    }
};
