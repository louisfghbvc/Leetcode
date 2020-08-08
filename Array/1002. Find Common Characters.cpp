// use Counting sort.
// O(N).

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int fre[26] = {};
        for(auto &c : A[0]){
            fre[c-'a']++;
        }
        for(int i = 1; i < A.size(); ++i){
            int tmp[26] = {};
            for(auto &c: A[i]){
                tmp[c-'a']++;
            }
            for(int k = 0; k < 26; ++k) fre[k] = min(fre[k], tmp[k]);
            
        }
        vector<string> res;
        for(int i = 0; i < 26; ++i){
            for(int k = 0; k < fre[i]; ++k){
                string s = string(1, i+'a');
                res.push_back(s);
            }
        }
        return res;
    }
};
