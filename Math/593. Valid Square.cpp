// Sort and check 4 edge equal. and check dot == 0.

class Solution {
public:
    double side(vector<int> &a, vector<int> &b){
        return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    }
    
    int dot(vector<int> &oa, vector<int> &oc){
        return oa[0]*oc[0] + oa[1]*oc[1];
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> arr = {p1, p2, p3, p4};
        sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        double a = side(arr[0], arr[1]), b = side(arr[0], arr[2]), c = side(arr[2], arr[3]), d = side(arr[1], arr[3]);
        if(a <= 0 || b <= 0 || c <= 0 || d <= 0) return false;
        if(a != b || b != c || c != d) return false;
        vector<int> ab = {arr[1][0]-arr[0][0], arr[1][1]-arr[0][1]};
        vector<int> ac = {arr[2][0]-arr[0][0], arr[2][1]-arr[0][1]};
        return dot(ab, ac) == 0;
    }
};

// O(1).
// use set, cuz int so that don't consider the double case.
class Solution {
public:
    int side(vector<int> &a, vector<int> &b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st = {side(p1, p2), side(p1, p3), side(p1, p4),
                                side(p2, p3), side(p2, p4), side(p3, p4)};
        return !st.count(0) && st.size() == 2;
    }
};
