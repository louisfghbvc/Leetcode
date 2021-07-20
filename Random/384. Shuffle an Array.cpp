// Each round every pair has same probability.
// 1 round 1/n 
// 2 round 1/n-1
// fisher yates algorithm 

class Solution {
public:
    vector<int> ord;
    vector<int> ret;

    Solution(vector<int>& nums) {
        ret = nums;
        ord = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ret = ord;
        return ret;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = ret.size()-1; i > 0; --i){
            int x = rand() % (i+1);
            swap(ret[x], ret[i]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
