// Simple Binary Search. O(logN).

class Solution {
public:
    int lower_bound(vector<int> &arr, int target){
        int n = arr.size();
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r-l)/2;
            if(arr[mid] >= target) r = mid;
            else l = mid+1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idl = lower_bound(nums, target);
        int idr = lower_bound(nums, target+1);
        --idr;
        if(idl > idr) return {-1, -1};
        return {idl, idr};
    }
};
