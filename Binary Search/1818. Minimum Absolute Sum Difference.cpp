// O(NlogN). lazy use set binary search 

class Solution {
public:
    const int mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long res = 0;
        set<long> st;
        for(int i = 0; i < n; ++i){
            res += abs(nums1[i] - nums2[i]);
            st.insert(nums1[i]);
        }
        long ans = res;
        for(int i = 0; i < n; ++i){
            auto p = st.upper_bound(nums2[i]);
            if(p != st.end()){
                long can = res - abs(nums1[i] - nums2[i]) + abs(*p - nums2[i]);
                if(can < ans) ans = can;
            }
            if(p != st.begin()){
                long can = res - abs(nums1[i] - nums2[i]) + abs(*prev(p) - nums2[i]);
                if(can < ans) ans = can;
            }
        }
        
        return ans % mod;
    }
};
