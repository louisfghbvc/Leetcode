class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;
        for(int x: nums) res.push_back(x);
        return res;
    }
};
