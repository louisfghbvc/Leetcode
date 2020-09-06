// O(N^4). A move right same as B move left.
// relative move. so just move right and down, and calculate the window is same.
class Solution {
public:
    int helper(vector<vector<int>>& a, vector<vector<int>>& b, int r, int c){
        int cnt = 0;
        int n = a.size();
        for(int i = 0; i < n && i + r < n; ++i){
            for(int j = 0; j < n && j + c < n; ++j){
                if(a[i][j] && a[i][j] == b[i+r][j+c]) cnt++;
                // same, cuz relative move.
                // if(a[i+r][j+c] && a[i+r][j+c] == b[i][j]) cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int res = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                res = max(helper(A, B, r, c), res);
                res = max(helper(B, A, r, c), res);
            }
        }
        return res;
    }
};
