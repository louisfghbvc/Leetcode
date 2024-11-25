class Solution {
public:

    bool finish(vector<vector<int>>& board) {
        return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 &&
                board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // goal: find the minimum nubmer of move to make win
        // [1,2,3]
        // [4,5,0]

        // idea:
        // make this board use visited state
        // bfs until finish

        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> vis;
        vis.insert(board);
        q.push(board);

        int step = 0;
        while (q.size()) {
            for (int qs = q.size(); qs; --qs) {
                auto cur = q.front(); q.pop();
                if (finish(cur)) return step;

                // next edge
                // find 0 position
                int i,j;
                bool ok = false;
                for (i = 0; i < 2; ++i) {
                    for (j = 0; j < 3; ++j) {
                        if (cur[i][j] == 0) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) break;
                }

                for (auto &[ni, nj]: {make_pair(i+1,j),{i-1,j},{i,j+1},{i,j-1}}) {
                    if (ni < 0 || ni >= 2 || nj < 0 || nj >= 3) continue;
                    
                    swap(cur[i][j], cur[ni][nj]);
                    if (vis.insert(cur).second) {
                        q.push(cur);
                    }
                    swap(cur[i][j], cur[ni][nj]);
                }
            }
            step++;
        }

        return -1;
    }
};
