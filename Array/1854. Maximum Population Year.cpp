// Line sweep. array tour. O(N).

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int fre[2055] = {};
        
        for(auto &x: logs){
            fre[x[0]]++;
            fre[x[1]]--;
        }
        
        int mx = 0, mxi = 0;
        int sum = 0;
        for(int i = 0; i <= 2050; ++i){
            sum += fre[i];
            if(sum > mx){
                mx = sum;
                mxi = i;
            }
        }
        return mxi;
    }
};
