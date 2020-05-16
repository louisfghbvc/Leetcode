// Gcd, and to_string.
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int d = 2; d <= n; ++d){
            for(int u = 1; u < d; ++u){
                if(__gcd(d, u) == 1){
                    ans.push_back(to_string(u)+"/"+to_string(d));
                }
            }
        }
            
        return ans;
    }
};
