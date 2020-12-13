// O(NlogN) mix strategy.
// think a = [1, 5]
//       b = [8, 2]
// so a1 + b1 = 9. a2 + b2 = 7.
// if choose a1. 1 - 2.
// if choose a2. 5 - 8. so 1-2 is better.
// so a1 - b2 > a2 - b1. => a1 + b1 > a2 + b2. so sort by sum. also can sort by difference.

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<int>> arr;
        for(int i = 0; i < n; ++i) arr.push_back({a[i]+b[i], i});
        sort(arr.begin(), arr.end(), [](vector<int> &l, vector<int> &r){
            return l[0] > r[0];
        });
        
        int sum = 0;
        for(int i = 0; i < n; ++i){
            if(i%2) sum -= b[arr[i][1]];
            else sum += a[arr[i][1]];
        }
        
        if(sum == 0) return 0;
        if(sum < 0) return -1;
        return 1;
    }
};
