// Tree dp. divide and conquer.
// today, i know the pascal's triangle magic... use for combination...
// so first seen is fixed root, the root is first and can't change.
// divide by root. to left part and right part. 
// and product all. but why is C[n-1][left_size] ?
// because the left and right must be in origin order and choose total position. so (total size)!/(left! * right!). note: left+right = total
// and just... wait like C right? C[total][left] = C[total][right]. ohhhh got it...
// O(N^2).

class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<long>> C; // pascal's triangle
    
    long dfs(vector<int> &A){
        int n = A.size();
        if(n <= 2) return 1;
        
        // root must be first.
        int root = A[0];
        
        vector<int> left, right;
        for(int i = 1; i < n; ++i){
            if(A[i] > root) right.push_back(A[i]);
            else left.push_back(A[i]);
        }
        
        // Divide and Conquer
        long lc = dfs(left);
        long rc = dfs(right);
        
        // total length
        int left_len = left.size(), right_len = right.size(); 
        return ( ( ( C[left_len + right_len][left_len] * lc ) % mod ) * rc ) % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // combination use pascal
        C.resize(n+1);
        for(int i = 0; i < n+1; ++i){
            C[i] = vector<long>(i+1, 1);
            for(int j = 1; j < i; ++j){
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
            }
        }
        
        return dfs(nums)-1;
    }
    
};

