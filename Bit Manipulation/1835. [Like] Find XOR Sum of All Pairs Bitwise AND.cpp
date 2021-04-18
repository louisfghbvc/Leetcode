// O(30N). record one. and if odd, add to local_xor.

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>> fre(31, vector<int>(2, 0));
        for(int x: arr1){
            for(int i = 30; i >= 0; --i){
                fre[i][x>>i&1]++;
            }
        }
        
        int res = 0;
        for(int x: arr2){
            int lc = 0;
            for(int i = 30; i >= 0; --i){
                if(x>>i&1){
                    if(fre[i][1]%2 == 1) lc = lc|(1<<i);
                }
            }
            res ^= lc;
        }
        return res;
    }
};
