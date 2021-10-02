// optimal solution. O(NM), use hashtable

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int res = 0;
        unordered_map<string, int> mp;
        for(auto &a: nums) mp[a]++;
        for(auto &[prefix, cnt]: mp){
            if(target.substr(0, prefix.size()) == prefix){
                auto suffix = target.substr(prefix.size());
                res += cnt * mp[suffix];
                if(prefix == suffix) res -= cnt; 
            }
        }
        return res;
    }
};

// Clean and concise. O(N^2)
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int res = 0;
        unordered_map<string, int> mp;
        for(auto &a: nums) mp[a]++;
        
        for(int i = 0; i+1 < target.size(); ++i){
            string l = target.substr(0, i+1);
            string r = target.substr(i+1);
            if(l == r) res += mp[l] * (mp[r]-1);
            else res += mp[l] * mp[r];
        }
        return res;
    }
};

// BF. O(N^3)
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                string tmp = nums[i] + nums[j];
                if(tmp == target) res++;
            }
        }
        return res;
    }
};
