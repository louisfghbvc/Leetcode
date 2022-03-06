// O(N), merge until no value

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // use a stack to simulate the process
        // merge the last two
        
        vector<int> res;
        for(int x: nums){
            res.push_back(x);
            while(res.size() > 1 && __gcd(res[res.size()-1], res[res.size()-2]) > 1){
                int v = res.back(); res.pop_back();
                res.back() = res.back() / __gcd(res.back(), v) * v;
            }
        }
        
        return res;
    } 
};
