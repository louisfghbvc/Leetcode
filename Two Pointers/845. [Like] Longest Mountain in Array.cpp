// T: O(N). Space: O(1). One pass. Cuz equal doesn't append mountain. so just forward and forward. 
// if up then can't go back. forward. no use in next mountain.
// Straight Forward.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size();
        for(int i = 0; i < n; ++i){
            int j = i;
            int up = 0, down = 0;
            if(j+1 < n && A[j] < A[j+1]){
                for(; j+1 < n && A[j] < A[j+1]; ++j) up++;
                for(; j+1 < n && A[j] > A[j+1]; ++j) down++;
                if(up && down) res = max(res, up+down+1);
                i = j-1;
            }
        }
        return res;
    }
};

// O(N^2). Enum all postion in array. try to go left and right. noob.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        for(int i = 0; i < A.size(); ++i){
            int l, r;
            for(l = i; l-1 >= 0 && A[l-1] < A[l]; --l);
            for(r = i; r+1 < A.size() && A[r+1] < A[r]; ++r);
            if(r-l+1 > 2 && r != i && l != i) res = max(res, r-l+1);
        }
        return res;
    }
};

// O(N). Space O(N). like Lis but continous.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> down(n), up(n);
        for(int i = n-2; i >= 0; --i){
            if(A[i] > A[i+1]) down[i] = down[i+1]+1;
        }
        for(int i = 1; i < n; ++i){
            if(A[i] > A[i-1]) up[i] = up[i-1]+1;
            if(up[i] && down[i]) res = max(res, up[i]+down[i]+1);
        }
        return res;
    }
};
