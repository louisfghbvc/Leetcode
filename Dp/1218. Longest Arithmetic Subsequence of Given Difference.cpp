// just use hashtable, and simliar to lis
// O(N)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        
        int res = 0;
        for(int x: arr){
            if(mp.count(x - difference))
                mp[x] = max(mp[x], mp[x-difference]+1);
            else mp[x] = 1;
            res = max(res, mp[x]);
        }
        
        return res;
    }
};
