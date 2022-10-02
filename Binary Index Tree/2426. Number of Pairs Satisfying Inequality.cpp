class Solution {
public:
    
    const int N = 7e4;
    int bit[70000]; 
    void add(int x) { 
        for (++x; x < N; x+=x&-x)
            bit[x]++;
    }
    
    long sum(int x) { // find the number in [0, x], O(logx)
        long res = 0;
        for (++x; x; x-=x&-x)
            res += bit[x];
        return res;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // goal: find the number of pairs, such that  nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
        // nums1[i] - nums2[i] + 3e4 <= nums1[j] - nums2[j] + diff + 3e4
        // rank_tree -> fenwick tree
        
        // find the rank of nums1[j] - nums2[j] + diff + 3e4 in the tree
        
        // nums1 = [3,2,5], nums2 = [2,2,1], diff = 1 
        // i = 0, nums1 - nums2 + diff = 3-2+1=2 -> how many number is smaller than 2? -> sum(2)
        
        
        memset(bit, 0, sizeof bit);
        
        long res = 0;
        int n = nums1.size();
        
        for (int i = 0; i < n; ++i) {
            int x = nums1[i] - nums2[i] + diff + 3e4;
            res += sum(x);
            add(nums1[i] - nums2[i] + 3e4);
        }
        
        return res;
    }
};
