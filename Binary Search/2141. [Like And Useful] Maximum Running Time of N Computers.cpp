// observe that greater value must use for a computer
// we want to divide these as evenly as possible. can be observe that it can work.
// O(N*log(Sum))

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        
        // guess answer try to close to target
        auto good = [&](long target){
            long tmp = 0;
            for(auto &x: batteries){
                tmp += min(target, long(x));
            }
            return tmp / n >= target;
        };
        
        long l = 0, r = sum;
        long ans = -1;
        while(l <= r){
            long mid = (l+r)>>1;
            if(good(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }

        return ans;
    }
};
