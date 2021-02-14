// O(NlogM). BS ans... ohh.
// So u want to use all operations and u can guess the maximum size called penalty.

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9+5;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(ok(nums, maxOperations, mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
    
    bool ok(vector<int> &nums, int maxOp, int val){
        for(int x: nums){
            int cut = x / val;
            if(x % val == 0) cut--;
            maxOp -= cut;
            if(maxOp < 0) return false;
        }
        return true;
    }
};
