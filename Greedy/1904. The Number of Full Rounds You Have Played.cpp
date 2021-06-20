// Enum.

class Solution {
public:
    
    int toINT(string &s){
        int h = (s[0] - '0') * 10 + s[1] - '0';
        int m = (s[3] - '0') * 10 + s[4] - '0';
        return h*60 + m;
    }
    
    int numberOfRounds(string startTime, string finishTime) {
        int A = toINT(startTime);
        int B = toINT(finishTime);
        
        if(B < A) B += 24 * 60;
        int res = 0;
        for(int i = 0; i < 48 * 60; i += 15){
            if(i >= A && i + 15 <= B) res++;
        }
        
        
        return res;
    }
};
