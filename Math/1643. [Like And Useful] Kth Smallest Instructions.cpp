// Observe that, build h possible nCr(tot-1, v). build v possible nCr(tot-1, v-1)
// if k <= h possible. say k is in the h. otherwise k is in the v. so sub h need. is new k.
// Very Tricky. O(R+C).
// build comb by pascal O(R*C).

class Solution {
public:
    int nCr[35][35];
    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1], v = destination[0];
        int n = h+v;
        for(int i = 0; i <= n; ++i){ // pascal triangle dp
            nCr[i][0] = nCr[i][i] = 1; 
            for(int j = 1; j < i; ++j){
                nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j]; // choice j or not 
            }
        }
        
        string res = "";
        for(int i = 0; i < n; ++i){
            int C = nCr[h-1+v][v]; // same as nCr[h+v-1][h-1]. but care h < 0. so use v
            if(k <= C) res += "H", --h;
            else res += "V", k -= C, --v;
        }
        
        return res;
    }
};
