// O(rc). record all col continous 1.
// and use stack to calculate rect.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int r = mat.size();
        if(!r) return 0;
        int c = mat[0].size();
        
        vector<vector<int>> cnt(r+1, vector<int>(c+1));
        for(int i = r-1; i >= 0; --i){
            for(int j = 0; j < c; ++j){
                if(mat[i][j] == '0') cnt[i][j] = 0;
                else cnt[i][j] = cnt[i+1][j]+1;
            }
        }
        
        int mx = 0;
        for(int i = 0; i < r; ++i){
            cnt[i][c] = -1;
            stack<int> st;
            int j = 0;
            while(j <= c){
                if(st.empty() || cnt[i][st.top()] < cnt[i][j]) st.push(j++);
                else{
                    int h = cnt[i][st.top()]; st.pop();
                    int w = st.empty() ? j : j - st.top()-1;
                    mx = max(mx, h*w);
                }
            }
        }
        
        return mx;
        
    }
};
