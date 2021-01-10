// N is small, so try to dfs + prune. from big to small
class Solution {
public:
    vector<int> arr;
    bool used[35];
    int n;
    bool dfs(int i){
        if(i == arr.size()) return true;
        if(arr[i]) return dfs(i+1);
        for(int k = n; k >= 1; --k){
            if(used[k]) continue;
            int dist = (k == 1 ? 0 : k);
            if(i+dist >= arr.size() || arr[i+dist]) continue;
            used[k] = 1;
            arr[i] = arr[i+dist] = k;
            if(dfs(i+1)) return true;
            used[k] = 0;
            arr[i] = arr[i+dist] = 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        if(n == 1) return {1};
        this->n = n;
        arr = vector<int>(2*n-1);
        dfs(0);
        return arr;
    }
};
