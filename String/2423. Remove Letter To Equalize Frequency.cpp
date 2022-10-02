class Solution {
public:
    bool equalFrequency(string word) {
        // goal: enumerate all index
        
        vector<int> fre(26);
        for (char c: word)
            fre[c-'a']++;
        
        for (char c: word) {
            fre[c-'a']--;
            set<int> fre_st;
            for (int x: fre) // O(26)
                if (x) fre_st.insert(x);
            if (fre_st.size() == 1)
                return true;
            fre[c-'a']++;
        }
        
        return false;
    }
};
