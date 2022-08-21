class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // goal: find the minimum operations need to recolor the blocks
        // idea: sliding window with size k, calculate the maximum black blocks
        
        int n = blocks.size();
        
        int b = 0; // calculate the black number
        for (int i = 0; i < k; ++i) {
            b += blocks[i] == 'B';
        }
        
        int mx = b;
        for (int i = k; i < n; ++i) {
            b -= blocks[i-k] == 'B'; 
            b += blocks[i] == 'B';
            mx = max(b, mx);
        }
        
        return k - mx;
    }
};
