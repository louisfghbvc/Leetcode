// Tricky. So we sort by x by desc, and if x is same y is small to big. 
// so that make sure if [10, 5], [10, 7]. (10, 5) can't have y
// fix one axis. greedy part is that, we only consider maximum y so far.
// O(NlogN)

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        int cnt = 0;
        int mx_y = -1;
        
        // first is decreasing, if x is same, second is increasing
        for(int i = 0; i < n; ++i){
            cnt += arr[i][1] < mx_y;
            mx_y = max(arr[i][1], mx_y);
        }
        
        return cnt;
    }
};

// Use set. find upperbound.
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        set<int> st;
        int cnt = 0;
        int mx = 0;
        // first is decreasing
        for(int i = n-1; i >= 0; --i){
            if(i+1 < n && arr[i][0] != arr[i+1][0]){
                st.insert(mx);
                mx = 0;
            }
            mx = max(mx, arr[i][1]);
            auto p = st.upper_bound(arr[i][1]);
            cnt += p != st.end();
        }
        
        return cnt;
    }
};
