// O(N). simple

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, x = 0;
        for(int h: gain){
            x += h;
            mx = max(mx, x);
        }
        return mx;
    }
};
