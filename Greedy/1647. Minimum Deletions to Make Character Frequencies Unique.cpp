// WA 1 times , array use char =_=
// O(N). each char check duplicate or not. until not duplicate.

class Solution {
public:
    int minDeletions(string s) {
        int fre[26] = {};
        for(char c: s) fre[c-'a']++;
        
        int res = 0;
        for(int i = 0; i < 26; ++i){
            unordered_set<int> st;
            for(int j = 0; j < 26; ++j) if(fre[j]>0 && j != i) st.insert(fre[j]);            
            while(fre[i] > 0 && st.count(fre[i])){
                fre[i]--;
                res++;
            }
        }
        return res;
    }
};

// count frequency. From big to small use diff. sort.
// O(N).
