// I use a prefix map. to count if 2 sum. check rest are sum.
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n+1);
        for(int i = 0; i < n; ++i) pre[i+1] = pre[i] + A[i];
        
        unordered_set<int> st;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += A[i];
            if(i+1 < n && sum%2 == 0 && st.count(sum - sum/2)){
                int t = pre[n] - pre[i+1];
                if(t == sum/2) return true;
            }
            st.insert(sum);
        }
        return false;
    }
};

// O(N). O(1). Tricky.
// Just think first sum, and part >= 3, return true. edge case is 0.
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int tot = accumulate(A.begin(), A.end(), 0);
        int n = A.size();
        if(tot % 3 != 0) return false;
        tot /= 3;
        int part = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            sum += A[i];
            if(sum == (part+1)*tot){
                part++;
            }
        }
        return part >= 3;
    }
};
