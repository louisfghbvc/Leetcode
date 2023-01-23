class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // use set
        
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        
        for (int x: st1) {
            if (st2.count(x))
                return x;
        }
        return -1;
    }
};
