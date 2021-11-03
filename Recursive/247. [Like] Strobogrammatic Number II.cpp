// recursive from O(n-2)
// use index to determine the first element is not leading zero

class Solution {
public:
    
    vector<string> helper(int n, int idx=0){
        if(n == 0) return {""};
        if(n == 1) return {"0", "1", "8"};
        vector<string> res;
        for(auto &s: helper(n-2)){
            for(int j = idx; j < 5; ++j)
                res.push_back("01689"[j] + s + "01986"[j]);
        }
        return res;
    }
    
    vector<string> findStrobogrammatic(int n) {
        return helper(n, 1);
    }
};
