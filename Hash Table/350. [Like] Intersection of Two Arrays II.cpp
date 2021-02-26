// O(M+N). Space O(N).

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // record dict. check nums
        unordered_map<int, int> mp;
        for(int x: nums1) mp[x]++;
        
        vector<int> res;
        for(int x: nums2){
            if(mp.count(x) && mp[x]-- > 0) res.push_back(x);
        }
        
        return res;
    }
};


// Sort and Compare like merge sort.
// O(NlogN)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        return res;
    }
};
