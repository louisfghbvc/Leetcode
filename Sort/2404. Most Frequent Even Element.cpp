class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        // goal: find the most even, and smallset
        // idea: record the even fre
        // and sort
        
        unordered_map<int, int> cnt;
        for (int x: nums) 
            if (x % 2 == 0)
                cnt[x]++;
        
        vector<pair<int, int>> arr;
        for (auto &[e, f]: cnt) {
            arr.push_back({f, e});
        }
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        
        if (arr.empty()) return -1; 
        return arr.front().second;
    }
};
