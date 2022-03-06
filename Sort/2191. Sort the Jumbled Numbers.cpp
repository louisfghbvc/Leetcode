// preprocessing.
// O(NlogN).

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto conv = [&](int x){
            if(!x) return mapping[0];
            int num = 0, f = 1;
            while(x){
                num += mapping[x%10]*f;
                f *= 10;
                x /= 10;
            }
            return num;
        };
        
        vector<pair<int, int>> arr;
        for(auto &x: nums)
            arr.push_back({conv(x), x});
        
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            return a.first < b.first; 
        });
        
        for(int i = 0; i < nums.size(); ++i)
            nums[i] = arr[i].second;
        
        return nums;
    }
};
