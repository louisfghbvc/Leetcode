// quick sort O(NlogN)
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>& b) {
        return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), cmp);
        for(int i = 0; i < K; ++i){
            res.push_back(points[i]);
        }
        return res;
    }
};

// solution2 nth_element O(N) worst case O(N^2)
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>& b) {
        return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin()+K, points.end(), cmp);
        points.resize(K);
        return points;
    }
};

// same as solution2 but implement by self. -> lomuto paritition <-
// divide and conquer. quick sort concept. cool.
// O(N).
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>& b) {
        return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
    }
    int helper(vector<vector<int>>& A, int l, int r){
        vector<int> p = A[r];
        int i = l;
        for(int j = l; j < r; ++j){
            if(cmp(A[j], p)){
                swap(A[i++], A[j]);
            }
        }
        swap(A[i], A[r]);
        return i;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size(), l = 0, r = n-1;
        while(l <= r){
            int mid = helper(points, l, r);
            if(mid == K) break;
            else if(mid < K) l = mid+1;
            else r = mid-1;
        }
        points.resize(K);
        return points;
    }
};
