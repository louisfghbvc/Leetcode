// Simple prefix sum concept. and calculate odd.
// O(N^2).

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        
        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j = i; j < n; ++j){
                sum += arr[j];
                if((j-i+1)&1) res += sum;
            }
        }
        
        return res;
    }
};
