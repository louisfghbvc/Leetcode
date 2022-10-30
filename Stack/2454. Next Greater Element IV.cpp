class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        // goal: find the second greater element of each number
        // idea: 
        // next greater -> decreasing stack -> 
        //                 i 
        //   [9, 10, 4, 0, 6]
        //  
        // f=[10, 4, 0],     6
        // s=[9, 4, 0],   
        
        // TC: O(3N), SC: O(N)
        
        stack<int> first, second;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (second.size() && nums[second.top()] < nums[i]) {
                res[second.top()] = nums[i];
                second.pop();
            }
            vector<int> todo;
            while (first.size() && nums[first.top()] < nums[i]) {
                todo.push_back(first.top()); 
                first.pop();
            }
            reverse(todo.begin(), todo.end());
            for (int x: todo)
                second.push(x);
            first.push(i);
        }
        return res;
    }
};
