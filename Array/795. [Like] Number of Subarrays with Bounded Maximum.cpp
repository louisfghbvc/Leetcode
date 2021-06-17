// O(N). Two pass. divide range to one. tricky. like prefix sum

class Solution {
public:
    int solve(vector<int> &arr, int bound){
        int n = arr.size();
        int mx = -1e9;
        int res = 0;
        for(int r = 0, l = 0; r < n; ++r){
            mx = max(mx, arr[r]);
            if(mx > bound){
                l = r+1;
                mx = -1e9;
            }
            res += r-l+1;
        }
        
        return res;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums, right) - solve(nums, left-1);
    }
};
