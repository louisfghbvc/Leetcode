class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        // goal: only use one carpet that can cover 
        // idea: use two pointers -> sliding window
        // sort the array
        
        sort(tiles.begin(), tiles.end());
        
        int n = tiles.size();
        
        int ans = 0;
        int number_whites = 0;
        
        for (int r = 0, l = 0; r < n && ans < carpetLen; ++r) {
            while (l <= r && tiles[l][0] + carpetLen <= tiles[r][1]) { // too much
                int partial = max(0, tiles[l][0] + carpetLen - tiles[r][0]);
                ans = max(number_whites + partial, ans);
                number_whites -= tiles[l][1] - tiles[l][0] + 1;
                l++;
            }
            number_whites += tiles[r][1] - tiles[r][0] + 1;
            ans = max(ans, number_whites);
        }
        
        return ans;
    }
};
