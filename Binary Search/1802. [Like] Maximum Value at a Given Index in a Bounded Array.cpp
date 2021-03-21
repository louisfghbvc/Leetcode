// Bullshit Math + Binary Search.
// O(logN).

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        int res = 0;
        while(l <= r){
            long mid = (l+r)/2;
            long val = mid;
            if(index+1 < n){
                int rn = mid - (n-1-index);
                if(rn < 1){
                    val += -(rn-1);
                    rn = 1;
                }
                val += (mid-1 + rn) * (mid-1 - rn + 1) / 2;
            }
            if(index > 0){
                int ln = mid - index;
                if(ln < 1){
                    val += -(ln-1);
                    ln = 1;
                }
                val += (mid-1 + ln) * (mid-1 - ln + 1) / 2;
            }
            if(val <= maxSum){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
};
