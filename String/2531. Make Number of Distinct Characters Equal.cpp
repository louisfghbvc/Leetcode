class Solution {
public:
    bool isItPossible(string word1, string word2) {
        // goal: one move to make distinct number is equal
        // idea:
        // case1: if the same -> true
        // case2: a>b, a -> b, 
        
        unordered_map<char, int> mp1, mp2;
        
        for (char c: word1)
            mp1[c]++;
        for (char c: word2)
            mp2[c]++;
        
        // O(26*26)
        for (char c0 = 'a'; c0 <= 'z'; ++c0) if(mp1.count(c0)) { // swap c0
            for (char c = 'a'; c <= 'z'; ++c) {
                if(--mp1[c0] == 0) mp1.erase(c0);
                mp2[c0]++;
    
                if (mp2.count(c)) {  // do swap
                    mp1[c]++;
                    if(--mp2[c] == 0) mp2.erase(c);
                    
                    if (mp1.size() == mp2.size()) return true;
                    
                    if(--mp1[c] == 0) mp1.erase(c);
                    mp2[c]++;
                }
                
                if(--mp2[c0] == 0) mp2.erase(c0);
                mp1[c0]++;
            }
        }   
        
        return false;
    }
};
