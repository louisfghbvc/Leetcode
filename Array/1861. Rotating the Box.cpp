// First, Rotate 90. 
// Second, from bottom count dot and boxes. then put it.

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                res[j][i] = box[i][j];
        
        for(int i = 0; i < n; ++i)
            reverse(res[i].begin(), res[i].end());
        
        // cout << "before\n";
        // for(int i = 0; i < n; ++i)
        //     for(int j = 0; j < m; ++j)
        //         cout << res[i][j] << " \n"[j==m-1];
        
        for(int j = 0; j < m; ++j){
            for(int i = n-1, ni; i >= 0; i = ni){
                ni = i;
                int dot = 0, bb = 0;
                while(ni >= 0 && res[ni][j] != '*'){
                    dot += res[ni][j] == '.';
                    bb += res[ni][j] == '#';
                    ni--;
                }
                for(int k = ni+1; k <= i; ++k){
                    if(dot > 0){
                        res[k][j] = '.';
                        dot--;
                    }
                    else if(bb > 0){
                        res[k][j] = '#';
                        bb--;
                    }
                }
                if(ni == i) ni--;
            }
        }
        
        // cout << "after\n";
        // for(int i = 0; i < n; ++i)
        //     for(int j = 0; j < m; ++j)
        //         cout << res[i][j] << " \n"[j==m-1];
        
        return res;
    }
};
