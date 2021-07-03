// O(M^2NlogN). Convert into 

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        auto getMax = [&](vector<int> &col){
            int pre = 0;
            set<int> st = {0};
            int res = INT_MIN;
            for(int x: col){
                pre += x;
                auto p = st.lower_bound(pre - k);
                if(p != st.end())
                    res = max(res, pre - *p);
                st.insert(pre);
            }
            return res;
        };
        
        int res = INT_MIN;
        for(int k = 0; k < m; ++k){
            vector<int> col(n);
            for(int i = k; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    col[j] += matrix[i][j];
                }
                res = max(res, getMax(col));
            }
        }

        return res;
    }
};


// Optimal
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        auto getMax = [&](vector<int> &col){
            int pre = 0;
            set<int> st = {0};
            int res = INT_MIN;
            for(int x: col){
                pre += x;
                auto p = st.lower_bound(pre - k);
                if(p != st.end())
                    res = max(res, pre - *p);
                st.insert(pre);
            }
            return res;
        };
        
        int res = INT_MIN;
        for(int _ = 0; _ < m; ++_){
            vector<int> col(n);
            for(int i = _; i < m; ++i){
                int tmp = 0, cur = INT_MIN; // maximum subarray
                for(int j = 0; j < n; ++j){
                    col[j] += matrix[i][j];
                    tmp = max(tmp + col[j], col[j]);
                    cur = max(cur, tmp);
                }
                if(cur <= k){
                    res = max(res, cur);
                    continue;
                }
                
                res = max(res, getMax(col));
            }
        }

        return res;
    }
};
