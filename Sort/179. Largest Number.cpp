// Simple sort. just compare 2 case. think greedy msb, lsb is fail.
// O(kNlogN)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // goal: find out the largest number 
        // we can rearrange them

        // idea:
        // "12" "3"

        // consider
        // "12" "121"
        // "12121" vs "12112"

        // sort by concate them, and consider which one is largest

        // e.g "9" "8" "7"
        // if 9 > 8, means 9 > 7

        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            string left = to_string(a) + to_string(b);
            string right = to_string(b) + to_string(a);
            return left > right;
        });

        string res;
        for (auto &x: nums)
            res += to_string(x);

        // need to fix leading zero!!
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());

        return res;
    }
};
