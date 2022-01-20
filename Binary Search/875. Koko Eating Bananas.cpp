// O(Nlogx)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search ans
         
        auto good = [&](int guess){
            int cnt = 0;
            for(int x: piles){
                cnt += (x + guess - 1) / guess;
            }   
            return cnt <= h;
        };
        
        int l = 1, r = 1e9;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(good(mid)) r = mid-1, ans = mid;
            else l = mid+1;
        }
        return ans;
    }
};
