// O(NlogN). O(N). use multiset to maintain this problem

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, -1);
        multiset<int> st(A.begin(), A.end());
        for(int i = 0; i < B.size(); ++i){
            auto p = st.upper_bound(B[i]);
            if(p != st.end()){
                res[i] = *p;
                st.erase(p);
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(res[i] == -1){
                res[i] = *st.begin();
                st.erase(st.begin());
            }
        }
        
        return res;
    }
};


// more clean

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> st(A.begin(), A.end());
        for(int i = 0; i < A.size(); ++i){
            auto p = st.upper_bound(B[i]);
            if(p == st.end())
                p = st.begin();
            A[i] = *p;
            st.erase(p);
        }
        return A;
    }
};
