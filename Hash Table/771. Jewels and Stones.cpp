// O(J+S)
// hash J.
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool vis[128] = {};
        for(const auto &c: J) vis[c] = 1;
        int ans = 0;
        for(const auto &c: S)
            if(vis[c]) ans++;
        return ans;
    }
};
