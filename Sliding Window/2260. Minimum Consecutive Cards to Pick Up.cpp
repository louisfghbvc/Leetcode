class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // goal: calculate the minimum length that can make only one matching pairs
        // idea: use two pointers
        
        unordered_map<int, int> mp; // record the number of frequency
        
        int n = cards.size();
        int res = n+1;
        for (int r = 0, l = 0; r < n; ++r) {
            mp[cards[r]]++;
            while (mp[cards[r]] == 2) {
                res = min(r - l + 1, res);
                mp[cards[l++]]--;
            }
        }
        
        return res == n+1 ? -1 : res;
    }
};
