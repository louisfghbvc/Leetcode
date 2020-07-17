// O(NlogK)

class Solution {
    typedef pair<int, int> ii;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto&x: nums) mp[x]++;
        vector<int> ans;
        priority_queue<ii> pq;
        for(auto &[key, fre]: mp){
            pq.push({fre, key});
            if(pq.size() > mp.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};

// O(N). Bucket Sort
class Solution {
    typedef pair<int, int> ii;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto&x: nums) mp[x]++;
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> ans;
        for(auto &[k, f]: mp){
            bucket[f].push_back(k);
        }
        for(int i = bucket.size()-1; i >= 0; --i){
            for(auto &v :bucket[i]){
                ans.push_back(v);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
