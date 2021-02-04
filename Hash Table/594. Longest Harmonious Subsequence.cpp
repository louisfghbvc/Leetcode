// this should be medium?
// O(NlogN) use map, and iterate key. 84ms. cuz this only traversal key.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        map<int, int> mp;
        for(int x: nums) mp[x]++;
        for(auto it = mp.begin(); next(it) != mp.end(); ++it){
            int a = it->first, b = next(it)->first;
            if(a+1 == b) res = max(res, it->second + next(it)->second);
        }
        return res;
    }
};



// O(N). use unordered_map to traversal 160ms.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        int res = 0;
        for(auto &[k, fre]: mp) if(mp.count(k-1))
            res = max(res, mp[k] + mp[k-1]);
        return res;
    }
};
