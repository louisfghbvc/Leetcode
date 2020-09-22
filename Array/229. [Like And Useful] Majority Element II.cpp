// voting algorithm, and floor(n/3), at most 2 major.
// O(N).
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int e1 = INT_MAX, e2 = INT_MAX, c1 = 0, c2 = 0; 
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == e1) c1++;
            else if(nums[i] == e2) c2++;
            else if(c1 == 0){
                e1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                e2 = nums[i];
                c2 = 1;
            }
            else c1--, c2--;
        }
        
        c1 = 0, c2 = 0;
        for(int x: nums){
            if(x == e1) c1++;
            else if(x == e2) c2++;
        } 
    
        if(c1 > nums.size()/3) res.push_back(e1);
        if(c2 > nums.size()/3) res.push_back(e2);
        
        return res;
    }
};
