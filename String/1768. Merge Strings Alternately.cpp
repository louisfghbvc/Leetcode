// Two Pointer. O(N+M)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string res = "";
        bool f = 1;
        while(i < word1.size() && j < word2.size()){
            if(f) res += word1[i++];
            else res += word2[j++];
            f ^= 1;
        }
        while(i < word1.size()) res += word1[i++];
        while(j < word2.size()) res += word2[j++];
        return  res;
    }
};
