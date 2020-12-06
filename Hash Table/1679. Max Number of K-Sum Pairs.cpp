// Simple two sum idea. O(N).
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        for(int x: nums){
            if(mp[k-x]){
                mp[k-x]--;
                res++;
            }
            else mp[x]++;
        }
        return res;
    }
};
