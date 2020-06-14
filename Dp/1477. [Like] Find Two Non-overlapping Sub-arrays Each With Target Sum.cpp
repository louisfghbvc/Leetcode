// True Solution use map and array.
// map can get prefix - target, if find then must prefix + target = now. has target
// so magic prefix map.
// then array means previous has ans or not
// so that must no over lapping

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int best = INT_MAX, res = INT_MAX;
        vector<int> mlen(n, INT_MAX);
        for(int i = 0; i < n; ++i){
            sum += arr[i];
            int k = sum - target;
            if(mp.find(k) != mp.end()){
                int prei = mp[k];
                if(prei > -1 && mlen[prei] != INT_MAX){
                    res = min(res, mlen[prei] + i-prei);
                }
                best = min(best, i-prei);
            }
            
            mlen[i] = best;
            mp[sum] = i;
        }
        return res == INT_MAX ? -1: res;
    }
};
