// WA... 1 time.
// only concern (5%~95%).
// and why/20, cuz if 5% means n/20. 
// 1% = n/100

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double tot = 0.0;
        int c = 0;
        for(int i = n/20; i+n/20 < n; ++i){
            tot += arr[i];
            c++;
        }
        return tot/c;
    }
};
