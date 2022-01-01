// O(NKlogNK).
// convert to a group, ans sort it, and use two pointers
// each window when have n index, then update the window range.

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // (num, id)
        vector<vector<int>> arr;
        for(int i = 0; i < nums.size(); ++i){
            for(int x: nums[i])
                arr.push_back({x, i});
        }
        
        sort(arr.begin(), arr.end());
        
        int n = nums.size();
        vector<int> cnt(n);
        int sz = 0;
        
        vector<int> res(2);
        res[0] = -1e8, res[1] = 1e8;
        
        for(int r = 0, l = 0; r < arr.size(); ++r){
            if(++cnt[arr[r][1]] == 1) sz++;
            while(sz == n){
                if(res[1] - res[0] > arr[r][0] - arr[l][0]){
                    res[0] = arr[l][0];
                    res[1] = arr[r][0];
                }
                if(--cnt[arr[l++][1]] == 0) sz--;
            }
        }
        
        return res;
    }
};
