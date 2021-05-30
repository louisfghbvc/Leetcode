// Mapping and use Union find O(N).

class Solution {
public:
    int n;
    vector<int> p;
    
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
    
    int longestConsecutive(vector<int>& nums) {
        n = nums.size();
        p = vector<int>(n, -1);
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) mp[nums[i]] = i;
        
        for(auto &[k, id]: mp){
            if(mp.count(k-1)){
                uni(id, mp[k-1]);
            }
            if(mp.count(k+1)){
                uni(id, mp[k+1]);
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(p[i] < 0)
                res = max(res, -p[i]);
        }
        return res;
    }
};

// Use map..
