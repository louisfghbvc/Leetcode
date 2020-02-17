//0ms 9.3MB
class Solution {
public:
    void dfs(vector<int> &res, int k, int &v){
        if(k == 0){
            res.push_back(v);
        }
        else{
            dfs(res, k - 1, v);
            v = v ^ (1<<(k-1));
            dfs(res, k - 1, v);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        int v = 0;
        dfs(res, n, v);
        return res;
    }
};

/**4ms 8.5MB
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < (1<<n); ++i){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
**/
