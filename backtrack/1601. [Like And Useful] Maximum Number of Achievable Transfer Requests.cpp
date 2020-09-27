// NP- Complete Problem.
// So just the euler graph. and find a longest circuit.
// when have cycle. the all points deg = 0. in deg = out deg.
// O(N2^E)
class Solution {
public:
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int res = 0;
        int es = requests.size(); 
        for(int i = 0; i < (1<<es); ++i){
            int deg[25] = {};
            for(int j = 0; j < es; ++j){
                if((1<<j)&i){
                    deg[requests[j][1]]++;
                    deg[requests[j][0]]--;
                }
            }
            auto check = [&](){
                for(int k = 0; k < n; ++k){
                    if(deg[k]) return false; 
                }
                return true;
            };
            if(check()) res = max(res, __builtin_popcount(i));
        }
        return res;
    }
};
