// Backtracking + simultate O(64^N * N^2), but more small.


class Solution {
    const int d[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
public:
    
    bool valid(int x, int y){
        return x >= 1 && x <= 8 && y >= 1 && y <= 8;
    }
    
    void check(){
        vector<int> s(step);
        auto xy = positions; 
        bool go = true;
        while (go) {
            go = false;
            for(int i = 0; i < n; ++i){
                if(s[i] > 0){
                    s[i]--;
                    xy[i][0] += d[direction[i]][0];
                    xy[i][1] += d[direction[i]][1];
                }
                if(s[i])
                    go = true;
            }
            for(int i = 0; i < n; ++i)
                for(int j = i + 1; j < n; ++j)
                    if (xy[i][0] == xy[j][0] && xy[i][1] == xy[j][1])
                        return;
        }
        ans++;
    }
    
    void dfs(int i){
        if(i == n){
            check();
            return;
        }
        direction.push_back(0);
        step.push_back(0);
        dfs(i + 1);
        direction.pop_back();
        step.pop_back();
            
        for (int j = 1; j < 8; ++j) {
            for (int k : possible[i]) {
                int x = positions[i][0] + d[k][0] * j, y = positions[i][1] + d[k][1] * j;
                if (valid(x, y)) {
                    direction.push_back(k);
                    step.push_back(j);
                    dfs(i + 1);
                    direction.pop_back();
                    step.pop_back();
                }
            }
        }
    }
    
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        n = pieces.size();
        possible = vector<vector<int>>(n);
        this->positions = positions;
        
        for(int i = 0; i < n; ++i){
            if(pieces[i] != "bishop"){
                possible[i].push_back(0);
                possible[i].push_back(2);
                possible[i].push_back(4);
                possible[i].push_back(6);
            } 
            if(pieces[i] != "rook"){
                possible[i].push_back(1);
                possible[i].push_back(3);
                possible[i].push_back(5);
                possible[i].push_back(7);
            } 
        }
        
        dfs(0);
        return ans;
    }
    
private:
    int n, ans = 0;
    vector<vector<int>> positions, possible;
    vector<int> direction, step;
};
