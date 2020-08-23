// Look at the function problem say. arr[i] add 1 or i~n arr[i]*2.
// So just think binary form.
// 5 = 101, must add 1 twice.
// and find significant bit. think about it.
// if 8 4 2. so calulate 8, no need to calculate 4 and 2. because can cover by 8.
// just like 1526.Minimum Number of Increments on Subarrays to Form a Target Array.
// QAQ

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int pre = 0;
        for(int &x: nums){
            res += __builtin_popcount(x);
            int k;
            for(k = 31; k >= 0; --k){
                if(x&(1<<k)) break;
            }
            if(k > pre){
                res += k-pre;
                pre = k;
            }
        }
        return res;
    }
};
