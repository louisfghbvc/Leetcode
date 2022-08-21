class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        // goal: find the minimum time that to no 01
        
        // 01 -> 10
        // 011 -> 101
        // 110
        // idea: simulate it
        // 00011
        // 00034 <- time
        
        int time = 0; 
        int zero = 0;
        for (char c: s) {
            zero += c == '0';
            if (c == '1') {
                if (zero)
                    time = max(time+1, zero);
            }
        }
        
        return time;
    }
};
