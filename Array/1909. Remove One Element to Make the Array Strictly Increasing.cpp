// O(N^2).

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        bool ok = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i-1] >= nums[i]) ok = 0;
        }
        if(ok) return 1;
        
        // remove 1
        for(int i = 0; i < n; ++i){
            vector<int> tmp;
            for(int j = 0; j < n; ++j) if(j != i) tmp.push_back(nums[j]);
            
            int m = tmp.size();
            bool ok = 1;
            for(int j = 1; j < m; ++j){
                if(tmp[j-1] >= tmp[j]) ok = 0;
            }
            if(ok) return 1;
        }
        
        return false;
    }
};

// O(N) . find one and remove left, or right.


// O(N). constructive algo
