// O(NlogM). well, just think that you need prefix sum.
// and update prefix. what data structure is satisfied? BIT.


class Solution {
public:
    const int mod = 1e9+7;
    int fre[100001];
    
    int query(int x){
        int res = 0;
        for(; x > 0; x -= x&-x){
            res += fre[x];
        }
        return res;
    }
    
    void update(int x){
        for(; x < 100001; x += x&-x){
            fre[x]++;
        }
    }
    
    int createSortedArray(vector<int>& A) {
        int res = 0, n = A.size();
        for(int i = 0; i < n; ++i){
            res = (res + min(query(A[i]-1), i-query(A[i]))) % mod;
            update(A[i]);
        }
        return res;
    }
};
