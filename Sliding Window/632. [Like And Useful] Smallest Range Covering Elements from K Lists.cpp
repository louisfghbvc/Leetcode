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

// convert the problem, choose each list a value, minimize the max-min
// TC: O(nklogk)
class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // goal: find the smallest range cover each range
        // idea:
        // each list choose smallest
        // record current minimum
        // move minimum -> range smaller

        vector<int> res(2);
        using T = array<int, 3>;
        priority_queue<T, vector<T>, greater<>> minHeap;

        int n = nums.size();
        
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i][0], 0, i});
            mn = min(mn, nums[i][0]);
            mx = max(mx, nums[i][0]);
        }

        res = {mn, mx};
        while (minHeap.size()) {
            auto [x, j, i] = minHeap.top(); minHeap.pop();
            if (j+1 < nums[i].size()) 
                minHeap.push({nums[i][j+1], j+1, i});
            else 
                break;
            mn = minHeap.top()[0];
            mx = max(mx, nums[i][j+1]);
            if (mx-mn < res[1]-res[0])
                res = {mn, mx};
        }

        return res;
    }
};
