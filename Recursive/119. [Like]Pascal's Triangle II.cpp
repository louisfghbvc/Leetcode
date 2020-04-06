//First use recursive + memorize. easy to understand
//space O(N^2)
class Solution {
public:
    int memo[35][35];
    int pascal(int r, int c){
        if(c == 0 || c == r) return 1;
        if(memo[r][c]) return memo[r][c];
        return memo[r][c] = pascal(r - 1, c) + pascal(r - 1, c - 1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; ++i){
            ans.push_back(pascal(rowIndex, i));
        }
        return ans;
    }
};

//Space O(N). Iterative. From back to begin
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; ++i){
            for(int j = i; j >= 1; --j){
                ans[j] += ans[j-1]; //because can't prefix. backward can avoid
            }
        }
        return ans;
    }
};
