// optimal solution
// O(N)

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // idea: remove duplicate and then just simple check adjacent element
        
        vector<int> arr;
        for (int x: nums) {
            if (arr.empty() || arr.back() != x)
                arr.push_back(x);
        }
        
        int cnt = 0;
        for (int i = 1; i+1 < arr.size(); ++i) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) cnt++;
            else if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) cnt++;
        }
        
        return cnt;
    }
};
