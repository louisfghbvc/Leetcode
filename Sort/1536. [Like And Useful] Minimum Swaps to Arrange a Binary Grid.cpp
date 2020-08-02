// Like bubble sort. and the key idea, check next is want, and swap.
// no need to back.
// Change tailing zero to a 1D array. Fast. this is trick.
// O(N^2)

class Solution {
public:
    int n;
    int cntZero(vector<int> &a){
        int cc = 0;
        for(int i = n-1; i >= 0; --i){
            if(a[i]) break;
            cc++;
        }
        return cc;
    }
    int minSwaps(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> arr;
        for(auto &r: grid){
            arr.push_back(cntZero(r));
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            int want = n-i-1;
            if(arr[i] < want){
                int j;
                for(j = i; j < n && arr[j] < want; ++j);
                if(j == n) return -1;
                res += j-i;
                for(; j > i; j--){
                    swap(arr[j], arr[j-1]);
                }
            }
        }
        return res;
    }
};
