class Solution {
public:
    int sum = 0;
    void dfs(vector<int> &arr){
        for(int i = 0; i < 26; ++i){
            if(arr[i] == 0) continue;
            sum++;
            --arr[i];
            dfs(arr);
            ++arr[i];
        }  
    }
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for(auto c : tiles)
            count[c - 'A']++;
        dfs(count);
        return sum;
    }
};
