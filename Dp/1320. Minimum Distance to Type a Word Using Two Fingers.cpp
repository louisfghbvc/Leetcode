class Solution {
    int moves(int word, int target){
        if(word == 26)
            return 0;
        int x = word / 6, y = word % 6;
        int x2 = target / 6, y2 = target % 6;
        return abs(x - x2) + abs(y - y2);
    }
public:
    int minimumDistance(string word) {
        if(word.size() == 2)
            return 0;
        int dp[word.size() + 1][27][27] = {};
        for(int i = 0; i < word.size(); ++i){
            for(int j = 0; j < 27; ++j){
                for(int k = 0; k < 27; ++k){
                    int finger1move = moves(j, word[i] - 'A');
                    int finger2move = moves(k, word[i] - 'A');
                    dp[i + 1][j][k] = min(dp[i][word[i] - 'A'][k] + finger1move, 
                                     dp[i][j][word[i] - 'A'] + finger2move);
                }
            }
        }
        return dp[word.size()][26][26];
    }
};
/*
2020.1.12 by louisfghbvc
time complexity O(N * 27 * 27)

all case do it, cache 
26 is no finger on keyboard so return it

*/
