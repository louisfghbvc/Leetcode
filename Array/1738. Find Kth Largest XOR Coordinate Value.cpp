// O(NMlogK). use priority_queue

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        priority_queue<int, vector<int>, greater<>> pq;
        
        for(int i = 0; i < m; ++i){
            int tx = 0;
            for(int j = 0; j < n; ++j){
                tx ^= mat[i][j];
                pq.push(tx);
                if(pq.size() > k) pq.pop();
            }
            if(i+1 < m){
                for(int j = 0; j < n; ++j)
                    mat[i+1][j] = mat[i+1][j]^mat[i][j];
            }
        }

        return pq.top();
    }
};
