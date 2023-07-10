class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        // goal: find the number of black blocks of exactly i black   
        
        // idea:
        // 2x2 simulate -> TLE
        
        // coordinates distinct
        // coordinates length <= 10^4
        
        // total number (m-1) * (n-1) ->
        // for each black check 4 add into 4 start block -> 
        
        
        long total = (long)(m-1)*(n-1);
        vector<long long> ans(5);
        ans[0] = total;
        
        map<pair<int, int>, int> cnt;
        
        for (auto &p : coordinates) {
            int x = p[0], y = p[1];    
            // add 4 valid start block   
            if (x-1 >= 0 && y-1 >= 0)
                cnt[{x-1,y-1}]++;
            if (x-1 >= 0 && y+1 < n)
                cnt[{x-1,y}]++;
            if (y-1 >= 0 && x+1 < m)
                cnt[{x,y-1}]++;
            if (x+1 < m && y+1 < n)
                cnt[{x,y}]++;
        }

        for (auto &[k, f]: cnt)
            ans[f]++;
        
        ans[0] -= ans[1]+ans[2]+ans[3]+ans[4];
        return ans;
    }
};
