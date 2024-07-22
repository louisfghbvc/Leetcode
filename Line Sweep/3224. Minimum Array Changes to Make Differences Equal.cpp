class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        // goal: find out the minimum changes to make all differences the same
        
        // idea:
        // we can try to find out the changes to make pairs to 0-k
        // using line sweep
        
        // k=4
        // if a=b, 
        // 0 1 2 3
        // 0 0 -> 0 1 1 1 
        // 0 1 -> 1 0 1 1
        // 0 2 ->     0 3
        // 0 3
        // 1 1
        // 1 2
        // 1 3
        // 2 3 -> - 0 1 1 2 
        
        // 1 3, r={0,1,2,3}

        // 0 change i = abs
        // 1 change i = 0 ~ max, where i!=abs
        // 2 change max~k
        
        int n = nums.size();
        vector<int> dif(k+2);
        for (int i = 0; i < n/2; ++i) {
            if (nums[n-i-1] < nums[i]) {
                swap(nums[i], nums[n-i-1]);
            }
            
            int a = nums[i], b = nums[n-i-1];
            int cur = b-a;
            int oneMax = max({k-a, a, b, k-b});
            
            // [0, oneMax] = 1
            // [0,cur-1], [cur+1, max]
            dif[0] += 1;
            dif[cur] -= 1;
            dif[cur+1] += 1;
            dif[oneMax+1] -= 1;
            
            // [r+1, k] => 2
            dif[oneMax+1] += 2;
        }
        
        for (int i = 1; i <= k; ++i)
            dif[i] += dif[i-1];
        
        return *min_element(dif.begin(), dif.begin()+k+1);
    }
};
