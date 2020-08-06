// if array mark twice. push_back to array.
// time: O(N). Space: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int id = abs(nums[i])-1;
            if(nums[id] > 0){
                nums[id] = -nums[id];
            }
            else{
                res.push_back(id+1);
            }
        }
        return res;
    }
};
