// Array to hash table, just like two sum.
// two case. if k == 0, special case. so just count frequency.
// otherwise just check val - k, why? if val-y==k => val-k == y
// O(N).

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
    
        int cnt = 0;    
        for(auto &[val, fre]: mp){
            if(!k){
                if(fre >= 2) cnt++;
            }
            else{
                if(mp.count(val-k)) cnt++;
            }
        }
        
        return cnt;
    }
};


// Noob, Straight.
// O(NlogN)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        set<pair<int, int>> ans;
        
        for(int x: nums){
            if(st.count(x-k)) ans.insert({x, x-k});
            st.insert(x);
        }
        
        return ans.size();
    }
};
