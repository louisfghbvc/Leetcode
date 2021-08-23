// Like 2D subarray maximum. compress 2D to 1D
// First u need to know how to calculate 1D
// [1,1] = 1+2
// so [1,1] => 1+2
//    [1,0] => and operator =>1, only take one row => 1
// = 1+2 +1 +1
// O(N^3)

class Solution {
public:
    int count1D(vector<int>& arr){
        int res = 0, len = 0;
        for(auto&x: arr){
            (x == 1) ? len++ : len=0;
            res += len;
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for(int u = 0; u < m; ++u){
            vector<int> col(n, 1);
            for(int d = u; d < m; ++d){
                for(int j = 0; j < n; ++j) col[j] &= mat[d][j];
                res += count1D(col);
            }
        }
        return res;
    }
};


// use stack, hard maximum area. O(MN). Space O(M)
// use prefix sum area 
class Solution {
public:
    
    int hist(vector<int> &mat){
        int n = mat.size();
        
        stack<int> st; 
        vector<int> sum(n);
        
        for(int i = 0; i < n; ++i){
            while(st.size() && mat[st.top()] >= mat[i]) st.pop();
            if(st.size()){
                int prev = st.top();
                sum[i] = sum[prev] + mat[i] * (i - prev);
            }
            else 
                sum[i] = mat[i] * (i+1);
            st.push(i);
        }
        
        return accumulate(sum.begin(), sum.end(), 0);
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        vector<int> row(m);
        for(int i = 0; i < n; ++i){ 
            for(int j = 0; j < m; ++j){
                row[j] = mat[i][j] ? row[j]+1 : 0;
            }
            res += hist(row);
        }
        return res;
    }
};
