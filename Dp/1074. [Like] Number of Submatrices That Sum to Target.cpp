// Convert problem to 1D. can u solve?.
// O(N^3). Space O(M)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        
        int res = 0;
        
        for(int k = 0; k < n; ++k){ // find all prefix
            vector<int> Rsum(m, 0); // prefix sum each row
            for(int i = k; i < n; ++i){
                // for(int j = 0; j < m; ++j)
                //     Rsum[j] += matrix[i][j];
                
                unordered_map<int, int> mp;
                mp[0] = 1;
                
                // 1D. easy to find
                int sum = 0; // sumr - target = suml
                for(int j = 0; j < m; ++j){
                    Rsum[j] += matrix[i][j];
                    sum += Rsum[j];
                    if(mp.count(sum - target)) res += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        
        return res;
    }
};
