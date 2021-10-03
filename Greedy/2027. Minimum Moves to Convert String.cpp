// Greedy. O(N). if cur is 'X', skip 3 steps.

class Solution {
public:
    int minimumMoves(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'X') res++, i+=2;
        }
        return res;
    }
};
