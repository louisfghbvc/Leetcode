// Consider 1 2 3 1 2. is same as 1 1 2 2 3. so we can simple sort. to change the maximum.

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mx = 1;
        arr[0] = 1;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - arr[i-1] > 1)
                arr[i] = arr[i-1] + 1;
            mx = max(mx, arr[i]);
        }
        
        return mx;
    }
};
