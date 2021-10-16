// Count A and B
// and you can determine A can win or not, A must greater than B.

class Solution {
public:
    bool winnerOfGame(string colors) {
        colors += '$';
        
        char prev = '0';
        int cnt = 0;
        int acnt = 0, bcnt = 0;
        for(char c: colors){
            if(prev != c){
                if(cnt >= 3){
                    if(prev == 'A') acnt += cnt-2;
                    else bcnt += cnt-2;
                }
                cnt = 1;
            }
            else cnt++;
            prev = c;
        }
        
        return acnt > bcnt;
    }
};
