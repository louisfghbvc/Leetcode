class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // goal: find the smallest sequence such that word1 is almost equal to word2
        
        // idea:
        // consider each index we can choose or not -> TLE
        
        // enumerate the bit we mask
        // n = 3
        
        // we have => O(n * (n + m))
        
        //     1~n
        // 0 | bc
        
        //       1 |    
        
        
        // can we enumerate the index? such that [0:i] match word2, [i+1:n] match word2
        // can we use prefix + suffix?

        // consider when we have lastMatch
        // when equal must use
        // when not equal check out if skip can match.
        
        
        int n = word1.size(), m = word2.size();
        vector<int> lastMatch(n, m);
        for (int i = n-1, j = m-1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                lastMatch[i] = j;
                j--;
            }    
            else {
                if (i+1 < n)
                    lastMatch[i] = lastMatch[i+1];
            }
        }
        
        vector<int> res;
        bool isSkip = true;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }
            else {
                if (isSkip && i+1 < n && lastMatch[i+1] <= j+1) {
                    isSkip = false;
                    res.push_back(i);
                    j++;
                }
            }
        }
        
        return res.size() == m ? res : vector<int>{};
    }
};
