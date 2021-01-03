// O(NlogN). fix left, search range.

class Solution {
public:
    const int mod = 1e9+7;
    int waysToSplit(vector<int>& nums) {
        long res = 0;
        int n = nums.size();
        
        vector<int> pre(n+1);
        for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + nums[i-1];
        
        for(int l = 1; l+1 <= n; ++l){
            int sl = l+1, sr = n-1;
            int left = pre[l];
            
            int ll = 1e9, rr = -1;
            while(sl <= sr){
                int mid = (sl + sr) / 2;
                int mid_s = pre[mid] - pre[l];
                int right = pre[n] -  pre[mid];
                if(mid_s < left){
                    sl = mid+1;
                }
                else if(mid_s > right){
                    sr = mid-1;
                }
                else sr = mid-1;
                if(left <= mid_s && mid_s <= right) ll = min(ll, mid);
            }
            
            sl = l+1, sr = n-1;
            while(sl <= sr){
                int mid = (sl + sr) / 2;
                int mid_s = pre[mid] - pre[l];
                int right = pre[n] -  pre[mid];
                if(mid_s < left){
                    sl = mid+1;
                }
                else if(mid_s > right){
                    sr = mid-1;
                }
                else sl = mid+1;
                if(left <= mid_s && mid_s <= right) rr = max(rr, mid);
            }
            
            if(ll == 1e9 || rr == -1 || ll > rr) continue;
            res += rr - ll + 1;
            if(res >= mod) res -= mod;
            
        }
        
        return res;
    }
};
