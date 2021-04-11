// O(N). just use 1 as sign...

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(int x: nums){
            if(x < 0) ans = -ans;
            if(x == 0) ans = 0;
        }
        return ans;
    }
};
