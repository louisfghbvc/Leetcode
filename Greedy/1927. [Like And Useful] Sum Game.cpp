// Game theory. O(N). need to think.

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int val = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; ++i){
            if(i < n/2){
                if(num[i] == '?') cnt++;
                else val += num[i] - '0';
            }
            else{
                if(num[i] == '?') cnt--;
                else val -= num[i] - '0';
            }
        }
        
        if(cnt & 1) return true;
        return val + cnt * 9 / 2 != 0;
    }
};
