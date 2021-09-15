// enum Case O(N).

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return n;
        
        int bigger = 0, smaller = 0;
        int res = 0;
        for(int i = 1; i < n; ++i){
            if(arr[i-1] > arr[i]){ // >
                bigger = smaller + 1;
                smaller = 0;
            }
            else if(arr[i-1] < arr[i]){ // <
                smaller = bigger + 1;
                bigger = 0;
            }
            else{ // =
                smaller = bigger = 0;
            }
            res = max({res, bigger, smaller});
        }
        
        return res + 1;
    }
};
