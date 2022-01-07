// reservoir sampling
class Solution {
public:
    Solution(vector<int>& nums) {
        arr = move(nums);
    }
    
    int pick(int target) {
        int cnt = 1;
        int res = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] == target){
                if(rand() % cnt++ == 0)
                    res = i;
            }
        }
        return res;
    }
    
private:
    vector<int> arr;
};



// use hashtable, and rand() O(1)
