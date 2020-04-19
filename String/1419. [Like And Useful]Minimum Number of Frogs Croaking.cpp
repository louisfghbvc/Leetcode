//Simulate. 5 state.
class Solution {
public:
    int minNumberOfFrogs(string frog) {
        int state[5] = {}, mx = 0, now = 0;
        for(auto &c: frog){
            int n = string("croak").find(c);
            state[n]++;
            if(n == 0){
                now++;
                mx = max(mx, now);
            }
            else if(--state[n-1] < 0) return -1;
            else if(n == 4) now--;
        }
        
        return now == 0 ? mx : -1;
    }
};
