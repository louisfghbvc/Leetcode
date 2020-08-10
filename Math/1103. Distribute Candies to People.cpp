// Math is hard.
// O(sqrt(candies)).
// because 1+2+..+n > 1e9. n is sqrt(1e9).
// still small. so simulate!!
class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        int i = 0, cnt = 1;
        while(candies){
            res[i++] += min(cnt, candies);
            if(candies < cnt) break;
            candies -= cnt++;
            i %= n;
        }
        return res;
    }
};
