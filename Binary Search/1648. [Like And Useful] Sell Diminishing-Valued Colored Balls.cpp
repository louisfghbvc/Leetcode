// A Fun Problem.
// step 1: sort from big to end.
// step 2: binary search the threshold, where use threshold can get total numbers >= orders. 
// step 3: calculate use math formula. 
// step 4: if orders remains. ans += orders * threshold.
// O(NlogM).

class Solution {
public:
    int mod = 1e9+7;
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());
        long l = 0, r = *max_element(inventory.begin(), inventory.end());
        
        long threshold = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            long tot = 0;
            for(int x: inventory){
                tot += max(0, x - mid + 1); // add 1. include mid. => [mid, x]
                if(tot >= orders) break;
            }
            if(tot >= orders) threshold = mid, l = mid+1;
            else r = mid-1;
        }

        long res = 0;
        for(int x: inventory){
            if(x <= threshold) break;
            long cnt = x - threshold;
            res = (res + cnt*(x+threshold+1)/2 % mod) % mod;
            orders -= cnt;
            if(orders <= 0) break;
        }
        if(orders > 0) res = (res + threshold*orders) % mod;
        return res;
    }
};

// Solution2. no sort. no need. autually.

// Solution3. use map as sort. threshold is l
class Solution {
public:
    int mod = 1e9+7;
    map<int, int, greater<int>> mp;
    bool valid(int mid, int od){
        for (auto &[val , cnt] : mp) {
            if (val <= mid) break;
            od -= (long)cnt * (val - mid);
            if (od <= 0) return true;
        }
        return od <= 0;
    }
    
    int maxProfit(vector<int>& inventory, int orders) {
        long res = 0;
        for(int x: inventory) mp[x]++;
        
        long l = 0, r = *max_element(inventory.begin(), inventory.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            if(valid(mid, orders)) l = mid+1;
            else r = mid-1;
        }
        
        for (auto &[val, cnt] : mp) {
            if(val <= l) break;
            orders -= cnt * (val - l);
            res = (res + (long)(val+l+1)*(val-l)/2 % mod * cnt % mod) % mod;
        }
        if(orders) res = (res + l * orders) % mod;
        return res;
    }
};
