// logtrick
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // goal: find the subarray such that the AND value is k
        // idea:
        
        // 01 10 11, k=1 
        //  1  0 1 , ans = 2
        
        // TC: O(n^2)
        // AND value is decreasing
        // when ending at index i, the AND value when we moving the left pointer, we only have at most 30
        // using hashmap
        
        unordered_map<int, long> cnt;
        long ans = 0;
        for (int x: nums) {
            unordered_map<int, long> next;
            for (auto &[a, f]: cnt) {
                next[a&x] += f;
            }
            next[x]++;
            swap(cnt, next);
            if (cnt.count(k))
                ans += cnt[k];
        }
        
        return ans;
    }
};
