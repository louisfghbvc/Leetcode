class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // goal: find the maximum score, such that choose k subsequence
        // idea: sort by num2, 
        // use min-heap
        // 
        
        int n = nums2.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums2[i] > nums2[j];
        });
        
        long ans = 0;
        long sum = 0;
        priority_queue<int, vector<int>, greater<>> min_heap;
        
        for (int o: idx) {
            int a = nums1[o], b = nums2[o];
            min_heap.push(a);
            sum += a;
            if (min_heap.size() > k) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            if (min_heap.size() == k) {
                ans = max(ans, sum*b);
            }
        }
        
        return ans;
    }
};
