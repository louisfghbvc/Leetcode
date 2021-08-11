// Greedy. From small num to big. O(NlogN).
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){ return abs(a) < abs(b); });
        unordered_map<int, int> mp;
        for(int x: arr)
            mp[x]++;
        for(int x: arr){
            if(mp[x] == 0) continue;
            if(mp[2*x] == 0) return false;
            mp[x]--;
            mp[2*x]--;
        }
        return true;
    }
};
