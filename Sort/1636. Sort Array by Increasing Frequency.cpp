// Simple sorting.

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> fre;
        for(int x: nums) fre[x]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return fre[a] < fre[b] || (fre[a]==fre[b] && a > b);
        });
        return nums;
    }
};
