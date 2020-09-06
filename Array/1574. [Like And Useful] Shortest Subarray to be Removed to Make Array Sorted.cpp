// cnt left, right, and merge. like prefix and suffix merge.
// O(N). Tricky.

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        while(left+1 < n && arr[left] <= arr[left+1]) left++;
        if(left == n-1) return 0;
        
        int right = n-1;
        while(right > left && arr[right-1] <= arr[right]) right--;
        
        int res = min(n-left-1, right);
        int i = 0, j = right;
        while(i <= left && j < n){
            if(arr[i] <= arr[j]){
                res = min(res, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        
        return res;
    }
};
