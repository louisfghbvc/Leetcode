//84ms 12.9MB, Like math, just try to find the largest num is the length or not
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), ans = 0, right = 0;
        for(long i = 1; i <= n; ++i){
            right = max(light[i - 1], right);
            if(right == i) ans++;
        }
        return ans;
    }
};
