// O(N). Like ISMP. and prefix map. map record index.
// prefix map like this pr - pl = target. now we change pr - target, so easily to find pl. no need to iterate
// 592ms.
class Solution {
public:
    typedef pair<int, int> ii;
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int res = 0, n = nums.size();
        int sum = 0;
        mp[0] = -1;
        vector<ii> arr;
        for(int r = 0; r < n; ++r){
            sum += nums[r];
            if(mp.count(sum-target)){
                arr.push_back({r, mp[sum-target]+1});
            }
            mp[sum] = r;
        }
        int x = -1;
        for(auto &[r, l]: arr){
            if(l > x){
                x = r;
                res++;
            }
        }
        return res;
    }
};

// O(N). Optimal use set.
// because no need left, if now find sum - target. so clear()
// the big is not the best choose. 
// 372ms
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> mp;
        int res = 0, n = nums.size();
        int sum = 0;
        mp.insert(0);
        for(int r = 0; r < n; ++r){
            sum += nums[r];
            if(mp.count(sum-target)){
                res++;
                mp.clear();
            }
            mp.insert(sum);
        }
        return res;
    }
};
