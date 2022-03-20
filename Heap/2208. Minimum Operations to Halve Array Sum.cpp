// O(nlogn), greedy

class Solution {
public:
    int halveArray(vector<int>& nums) {
        // goal: minimum number of ops to reduce the sum at least half
        // idea: choose the maximum value -> divide half
        // greedy and use a max-heap
        
        double sum = 0, tot = accumulate(nums.begin(), nums.end(), 0.0);
        priority_queue<double> heap;
        for (auto &x: nums)
            heap.push(x);
        
        int ops = 0;
        while (sum < tot/2) {
            double val = heap.top(); heap.pop();
            sum += val / 2;
            heap.push(val / 2);
            ops++;
        }
        
        return ops;
    }
};
