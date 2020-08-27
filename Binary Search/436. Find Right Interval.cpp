// Sort left point, Binary serach the right position.
// O(NlogN) use map.
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        map<int, int> mp;
        int n = intervals.size();
        for(int i = 0; i < n; ++i) mp[intervals[i][0]] = i;
        for(int i = 0; i < n; ++i){
            auto it = mp.lower_bound(intervals[i][1]);
            if(it == mp.end()) res.push_back(-1);
            else res.push_back(it->second);
        }
        return res;
    }
};

// sort + bs.
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        for(int i = 0; i < n; ++i){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        auto bs = [&](int t){
            int l = 0, r = n-1;
            int ans = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(intervals[mid][0] >= t) ans = mid, r = mid - 1;
                else l = mid+1;
            }
            return ans;
        };
        
        for(int i = 0; i < n; ++i){
            int fd = bs(intervals[i][1]);
            if(fd != -1) res[intervals[i][2]] = intervals[fd][2];
        }
        return res;
    }
};
