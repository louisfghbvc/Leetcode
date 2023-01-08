class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // goal: find the maximum k elements
        // idea: maxheap
            
        priority_queue<int> pq(nums.begin(), nums.end());
        long ans = 0;
        while (k--) {
            int x = pq.top(); pq.pop();
            ans += x;
            pq.push((x+2)/3);
        }
        return ans;
    }
};


// Solution2, Map, O(nlogn)
