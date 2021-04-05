// O(NlogN). Tricky. Enum all gcd.

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> cnt(mx+1);
        for(int x: nums) cnt[x] = 1;
        int res = 0;
        for(int i = 1; i <= mx; ++i){
            int g = 0;
            for(int j = i; j <= mx; j += i){
                if(cnt[j]){
                    g = __gcd(g, j);
                    if(g == i){
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
