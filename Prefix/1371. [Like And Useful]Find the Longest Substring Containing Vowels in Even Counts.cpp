//use hash record all state, like dp, make vowel to bit, cool, 92ms 17.6MB
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, bmask = 0;
        
        vector<int> state(32, -2);
        state[0] = -1;
        string vowels = "aeiou";
        
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < 5; ++j){
                if(s[i] == vowels[j]){
                    bmask ^= (1<<j); 
                    break;
                }
            }
            if(state[bmask] != -2)
                ans = max(ans, i - state[bmask]);
            else
                state[bmask] = i;
        }
        
        return ans;
    }
};
