// O(N^2). Sum + sort.
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int, int>> arr;
        for(int i = 0; i < mat.size(); ++i){
            arr.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; ++i) res.push_back(arr[i].second);
        return res;
    }
};

// Optimal. Binary Search 0. + Set Size K.
class Solution {
public:
    int getNum(const vector<int> &a){
        int n = a.size(), l = 0, r = n;
        while(l < r){
            int mid = (l+r)/2;
            if(a[mid]) l = mid+1;
            else r = mid;
        }
        return l+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        set<pair<int, int>> st;
        for(int i = 0; i < mat.size(); ++i){
            st.insert({getNum(mat[i]), i});
            if(st.size() > k) 
                st.erase(prev(st.end()));
        }
        for(auto &[n, id]: st) 
            res.emplace_back(id);
        return res;
    }
};
