// so build a pattern
// and for loop check pattern frequency.
// O(N^2)

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for(int i = 0; i+m < n; ++i){
            int cnt = 0;
            vector<int> p(arr.begin()+i, arr.begin()+i+m);
            int ps = p.size();
            for(int j = i, k = 0; j < n; ++j){
                if(arr[j] == p[k]) k++;
                else break;
                if(k == ps) k = 0, cnt++;
            }
            if(cnt == k) return true;
        }
        return false;
    }
};
