// O(N^2). Not optimal.
// Straight forward.
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res = code;
        int n = code.size();
        if(k > 0){
            for(int i = 0; i < n; ++i){
                int sum = 0;
                for(int j = 0; j < k; ++j){
                    sum += code[(i+1+j)%n];
                }
                res[i] = sum;
            }
        }
        else if(k == 0) for(int &x: res) x = 0;
        else{
            k = -k;
            for(int i = 0; i < n; ++i){
                int sum = 0;
                for(int j = 0; j < k; ++j){
                    sum += code[(i-1-j + n)%n];
                }
                res[i] = sum;
            }
        }
        return res;
    }
};

// O(N) sliding window.
