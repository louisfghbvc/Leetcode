// Hard to think, construct all prefix and suffix. find prefix and suffix, that is.
// edge case hard to think, pretty hard. O(NK^2).
// build all possible.

class Solution {
public:
    
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        
        int n = words.size();
        for(int i = 0; i < n; ++i){
            mp[words[i]] = i;
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= words[i].size(); ++j){
                
                // if suffix is palindrome.
                if(isPalindrome(words[i], j, words[i].length()-1)){
                    
                    // check reverse left part is exist.
                    string left = words[i].substr(0, j);
                    reverse(left.begin(), left.end());
                    
                    if(mp.count(left) && mp[left] != i)
                        res.push_back({i, mp[left]});
                }
                
                // if prefix is palindrome
                if(j > 0 && isPalindrome(words[i], 0, j-1)){
                    
                    // check reverse right part is exist.
                    string right = words[i].substr(j);
                    reverse(right.begin(), right.end());
                    
                    if(mp.count(right) && mp[right] != i)
                        res.push_back({mp[right], i});
                }
            }
        }
        
        return res;    
    }
};
