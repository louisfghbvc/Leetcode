// O(N). Tricky. because array are 0~n. so just maintain max.
// if i == max, means that position is cut point so that sort correct.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunk = 0, mx = 0;
        for(int i = 0; i < n; ++i){
            mx = max(mx, arr[i]);
            if(i == mx) chunk++;
        }
        return chunk;
    }
};
