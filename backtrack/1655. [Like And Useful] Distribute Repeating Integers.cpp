// m == 10. n == 50. backtracking.
// O(?) exponential time.
class Solution {
public:
    vector<int> arr;
    vector<int> qt;
    bool dfs(int i){
        if(i >= qt.size()) return true;
        for(int j = 0; j < arr.size(); ++j){
            if(arr[j] >= qt[i]){
                arr[j] -= qt[i];
                if(dfs(i+1)) return true;
                arr[j] += qt[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);
        sort(arr.rbegin(), arr.rend());
        qt = quantity;
        sort(qt.rbegin(), qt.rend());
        return dfs(0);
    }
};

// Dp.
