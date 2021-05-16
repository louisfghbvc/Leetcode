// See constraints.

class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    vector<int> ord;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int x: nums2) mp[x]++;
        arr = nums1;
        ord = nums2;
    }
    
    void add(int index, int val) {
        int tmp = ord[index];
        mp[tmp]--;
        ord[index] += val;
        mp[ord[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int x: arr)
            if(mp.count(tot - x)) res += mp[tot-x];
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
