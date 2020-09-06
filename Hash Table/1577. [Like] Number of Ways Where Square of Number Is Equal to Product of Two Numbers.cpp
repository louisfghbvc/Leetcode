// Like prefix map.
// remember to clear mp. and monotonous because j<k, so just calculate k.
// O(NM)
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int x: nums1){
            long t = (long)x*x;
            mp.clear();
            for(int j = 0; j < nums2.size(); ++j){
                if(t % nums2[j] == 0){
                    res += mp[t/nums2[j]];
                }
                mp[nums2[j]]++;
            }
        }
        for(int x: nums2){
            long t = (long)x*x;
            mp.clear();
            for(int j = 0; j < nums1.size(); ++j){
                if(t % nums1[j] == 0){
                    res += mp[t/nums1[j]];
                }
                mp[nums1[j]]++;
            }
        }
        return res;
    }
};
