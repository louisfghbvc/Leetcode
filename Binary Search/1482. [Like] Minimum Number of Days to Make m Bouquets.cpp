// Hard to think. Binary Search. 
// The magic is guess ans, and divide and conquer
// O(NlogV)

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/k < m) return -1;
        vector<int> t = bloomDay;
        sort(t.begin(), t.end());
        vector<bool> vis(n);
        int l = *t.begin(), r = *t.rbegin();
        int res = 0;
        while(l <= r){
            int mid = (l+r)/2;
            for(int i = 0; i < n; ++i){
                if(bloomDay[i] <= mid) vis[i] = 1;
                else vis[i] = 0;
            }
            int c = 0, tc = 0;
            for(int i = 0; i < n; ++i){
                if(vis[i]) c++;l
                else c= 0;
                if(c == k){
                    tc++;
                    c = 0;
                }
            }
            if(tc >= m){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};
