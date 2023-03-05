class Solution {
public:
    int passThePillow(int n, int time) {
        // goal: find the index that holding pillow
        // idea: simulate
        // 1,2,3,2
        
        // TC: O(n)
        
        vector<int> arr;
        for (int i = 1; i <= n; ++i)
            arr.push_back(i);
        for (int i = n-1; i >= 2; --i)
            arr.push_back(i);
        return arr[time % arr.size()];
    }
};
