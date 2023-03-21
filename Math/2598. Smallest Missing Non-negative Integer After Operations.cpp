class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // goal: find the maximum mex values apply operations
        // idea:
        // we want to make all values cover 0,....
        // divide same mod to same group
        
        vector<int> group(value);
        for (int x: nums)
            group[((x % value) + value) % value]++;
        
        int mex = 0;
        while (group[mex % value]) {
            group[mex%value]--;
            mex++;
        }
        return mex;
    }
};
