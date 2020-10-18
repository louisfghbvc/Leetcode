// Just Enum.
// O(N^2).

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int l = -1;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(s[i] == s[j]) l = max(l, j-i-1);
            }
        }
        return l;
    }
};

// O(N). record first index.
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int l = -1;
        int n = s.size();
        vector<int> ind(26, n);
        for(int i = 0; i < n; ++i){
            ind[s[i]-'a'] = min(i, ind[s[i]-'a']);
            l = max(l, i-ind[s[i]-'a']-1);
        }
        return l;
    }
};
