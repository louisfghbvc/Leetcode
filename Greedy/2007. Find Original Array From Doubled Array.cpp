// From small to big, just pairing. similar LC 954.
// O(NlogN).

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        int n = changed.size();
        if(n & 1) return res;
        
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        for(int x: changed) mp[x]++;
        
        for(int x: changed){
            if(mp[x] == 0) continue;
            if(mp[2*x] > 0){
                mp[x]--;
                mp[2*x]--;
                res.push_back(x);
            }
            else{
                return {};
            }
        }
        
        return res;
    }
};


// Clean, use map. O(NlogN).
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        int n = changed.size();
        if(n & 1) return res;
        
        map<int, int> mp;
        for(int x: changed) mp[x]++;
        
        for(auto &[k, v]: mp){
            while(v--){
                if(--mp[2*k] < 0) return {};
                res.push_back(k);
            }
        }
        
        return res;
    }
};
