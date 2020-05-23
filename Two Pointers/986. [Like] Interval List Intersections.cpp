// Solution 1, O(M*N), Just simple
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        for(const auto& l: A){
            for(const auto& r: B){
                if(l[1] < r[0] || r[1] < l[0]) continue;
                ans.push_back({max(l[0], r[0]), min(l[1], r[1])});
            }
        }
        return ans;
    }
};

// Solution 2, merge concept. O(m+n)
// think it. if node can be merged, why not line.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        for(int i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? i++ : j++){
            int st = max(A[i][0], B[j][0]);
            int ed = min(A[i][1], B[j][1]);
            if(st <= ed) ans.push_back({st, ed});
        }
        return ans;
    }
};
