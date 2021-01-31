// simple O(NlogN)

class Solution {
public:
    int countBalls(int l, int r) {
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i = l; i <= r; ++i){
            int x = 0, val = i;
            while(val){
                x += val%10;
                val /= 10;
            }
            mp[x]++;
            if(mp[x] > mx) mx = mp[x];
        }
        return mx;
    }
};
