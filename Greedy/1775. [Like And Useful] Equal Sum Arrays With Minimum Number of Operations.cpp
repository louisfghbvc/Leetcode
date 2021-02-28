// O(NlogN). greedy trick + two pointer. just go bigger.
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > 6*m || m > 6*n) return -1;
        
        int s1 = 0, s2 = 0;
        for(int x: nums1) s1 += x;
        for(int x: nums2) s2 += x;
        
        if(s1 > s2){
            return minOperations(nums2, nums1);
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int diff = s2 - s1, i = 0, j = m-1;
        
        int ops = 0;
        while(diff > 0){
            if(j < 0 || 6 - nums1[i] > nums2[j] - 1){
                diff -= 6 - nums1[i++];
            }
            else{
                diff -= nums2[j--] - 1;
            }
            ops++;
        }
        
        return ops;
    }
};


// O(V). Enum all possible. get smaller.
class Solution {
public:
    int helper(vector<int> fre, int dis){
        int ops = 0;
        if(dis > 0){
            for(int i = 1; i <= 5; ++i){
                int get = 6 - i;
                int t = min((dis + get - 1)/ get, fre[i]);
                dis -= t * get;
                ops += t;
                if(dis <= 0) break;
            }
        }
        else{
            dis = -dis;
            for(int i = 6; i >= 2; --i){
                int get = i - 1;
                int t = min((dis + get - 1)/ get, fre[i]);
                dis -= t * get;
                ops += t;
                if(dis <= 0) break;
            }
        }
        if(dis > 0) return 1e6;
        return ops;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > 6*m || m > 6*n) return -1;
        
        vector<int> fre1(7), fre2(7);
        int s1 = 0, s2 = 0;
        for(int x: nums1) fre1[x]++, s1 += x;
        for(int x: nums2) fre2[x]++, s2 += x;
        
        int ops = n + m;
        int l = max(n, m), r = min(6*n, 6*m);
        for(int s = l; s <= r; ++s){
            ops = min(ops, helper(fre1, s - s1) + helper(fre2, s - s2));
        }
        return ops;
    }
};
