//0ms 7.7MB
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> t = heights;
        sort(t.begin(), t.end());
        for(int i = 0; i < n; ++i){
            if(t[i] != heights[i])
                ans++;
        }
        return ans;
    }
};
