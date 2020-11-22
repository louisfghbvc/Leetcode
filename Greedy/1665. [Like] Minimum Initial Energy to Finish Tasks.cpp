// So sort it . and just Binary Search it.
// how to sort? think [1,7] [5,9]. which is better? so 1+9 < 5+7 [1,7] is better.
// alternative thinking. 7-1 > 9-5. so [1,7] do first.
// O(nlogn + nlogx).

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0;
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b){
            int l = a[0]+b[1];
            int r = a[1]+b[0];
            return l < r; 
        });
        
        auto check = [&](int x){
            int st = x;
            for(int i = 0; i < n; ++i){
                if(st < tasks[i][1]) return false;
                st -= tasks[i][0];
            }
            return true;
        };
        
        int l = 0, r = 1e9+5;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid)) res = mid, r = mid-1;
            else l = mid+1;
        }
        
        return res;
    }
};

// O(nlogn). O(n). just use borrow method
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0;
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b){
            int l = a[0]+b[1];
            int r = a[1]+b[0];
            return l < r; 
        });
        
        int sta = 0;
        for(auto &t: tasks){
            if(sta < t[1]){
                int borrow = t[1] - sta;
                res += borrow;
                sta = t[1];
            }
            sta -= t[0];
        }
        return res;
    }
};
