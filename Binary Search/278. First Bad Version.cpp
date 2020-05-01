// Simple Binary Search.
// watch out overflow, use long or l + (r-l)/2
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, ans = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
