// binary search the ans
// O(NlogX).

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto good = [&](int largest){
            int val = 0, cnt = 1; // group value, group size
            for(int x: nums){
                if(x > largest) return false;
                if(val + x > largest){
                    cnt++;
                    val = x;
                }
                else val += x;
            }
            return cnt <= m;
        };
        
        int tot = accumulate(nums.begin(), nums.end(), 0);
        
        // binary search the ans
        int l = 0, r = tot;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(good(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        return ans;
    }
};
