// BFS. watch out so many duplicate, so just use set.
// but observely. just like triangle
class Solution {
public:
    double dp[105][105];
    double champagneTower(int poured, int query_row, int query_glass) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = poured;
        while(q.size()){
            set<pair<int, int>> st;
            for(int s = q.size()-1; s >= 0; s--){
                auto [i, j] = q.front(); q.pop();
                if(dp[i][j] > 1){
                    double diff = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    if(i+1 <= query_row){
                        dp[i+1][j] += diff/2.0;
                        if(!st.count({i+1, j})){
                            st.insert({i+1, j});
                            q.push({i+1, j});
                        }
                    }
                    if(i+1 <= query_row){
                        dp[i+1][j+1] += diff/2.0;
                        if(!st.count({i+1, j+1})){
                            st.insert({i+1, j+1});
                            q.push({i+1, j+1});
                        }
                    }
                }
            }
            
        }
        return dp[query_row][query_glass];
    }
};

// force bfs. O(N^2).
// Dp
class Solution {
public:
    double dp[105][105];
    double champagneTower(int poured, int query_row, int query_glass) {
        dp[0][0] = poured;
        for(int i = 0; i < 100; ++i){
            for(int j = 0; j < 100; ++j){
                if(dp[i][j] > 1){
                    double diff = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += diff/2.0;
                    dp[i+1][j+1] += diff/2.0;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};
