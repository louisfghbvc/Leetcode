class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // goal: find out kth smallest distance pair
        // idea:
        // a pair(i, j) -> |nums[i] - nums[j]|
        // binary search the answer
        // distance = 0 ~ max - min
        // F(d): number of pairs such that smaller or equal than d

        // we can sort the array and using two pointers
        // 1 1 3 4, d = 2
        // ^   ^ 
        // when nums[j]-nums[i] > d => need decrease the window
        // when a valid window [i,j] => we have j-i pairs, ending at j 

        ranges::sort(nums);

        int n = nums.size();
        auto F = [&](int x) {
            int cnt = 0;
            for (int r = 0, l = 0; r < n; ++r) {
                while (nums[r] - nums[l] > x) {
                    l++;
                }
                cnt += r - l;
            }
            return cnt;
        };

        int l = 0, r = nums[n-1] - nums[0];
        int ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (F(m) >= k) ans = m, r = m-1;
            else l = m+1;
        }
        return ans;
    }
};
