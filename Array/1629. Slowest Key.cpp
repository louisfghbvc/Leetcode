// Problem statement so long...
// O(N). Simple..

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int t = 0;
        int mx = 0;
        char c = 0;
        int n = releaseTimes.size();
        for(int i = 0; i < n; ++i){
            int d = releaseTimes[i] - t;
            if(d > mx){
                mx = d;
                c = keysPressed[i];
            }
            else if(d == mx)
                c = max(c, keysPressed[i]);
            t = releaseTimes[i];
        }
        return c;
    }
};
