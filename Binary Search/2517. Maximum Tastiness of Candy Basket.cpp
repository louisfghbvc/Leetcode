class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        // goal: choose k candies, maximum the minimum abs price
        // idea:
        // [13,5,1,8,21,2], k = 3
        //  1,2,5,8,13,21, guess abs >= 3
        //      ^
        //  1,5,8
        //  
        
        // guess the ans
        // sort the array
        // add a number, calculate the min abs, if not good remove that number
        // check the size >= k
        
        sort(price.begin(), price.end());
        
        auto good = [&](int dif) {
            vector<int> ans;
            for (int x: price) {
                if (ans.empty()) ans.push_back(x);
                else {
                    int d = x - ans.back();
                    if (d >= dif)
                        ans.push_back(x);
                }
            }
            return ans.size() >= k;
        };
        
        
        long l = 0, r = 1e14;
        long ans = 0;
        while (l <= r) {
            long mid = (l+r)/2;
            if (good(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};
