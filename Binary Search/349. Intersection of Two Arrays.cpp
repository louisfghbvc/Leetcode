//4ms 8MB
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        for(int i = 0; i < nums1.size(); ++i){
            if(i != 0 && nums1[i] == nums1[i - 1]) continue;
            int tmp = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if(tmp < nums2.size() && nums2[tmp] == nums1[i]){
                ans.push_back(nums1[i]);
            }
        }
            
        return ans;
    }
};
