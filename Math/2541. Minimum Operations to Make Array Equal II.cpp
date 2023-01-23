class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        // goal: calculate the minimum operations, make nums1 == nums2
        // op: choose i,j, and num1[i]+=k, nums1[j] -= k 
        // order can not change
        // idea:
        // each number is too small add
        // 4,3,1,4 -> 1,3,7,1
        // 
        
        int n = nums1.size();
        
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                if (nums1[i] != nums2[i])
                    return -1;
            }    
            return 0;
        }
        
        long ups = 0;
        long dps = 0;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) continue;
            int dis = abs(nums1[i]-nums2[i]);
            if (dis % k) return -1;
            if (nums1[i] > nums2[i])
                dps += dis/k;
            if (nums1[i] < nums2[i])
                ups += dis/k;
        }
        
        if (ups != dps) return -1;
        
        return ups;
    }
};
