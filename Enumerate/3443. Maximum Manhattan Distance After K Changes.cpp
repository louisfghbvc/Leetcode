class Solution {
public:

    int change(string p, string s, int k) {
        unordered_map<char, char> ch;
        ch['N'] = 'S';
        ch['S'] = 'N';
        ch['E'] = 'W';
        ch['W'] = 'E';

        int x = 0, y = 0, ans = 0;
        for (char c: s) {
            if (c == p[0]) {
                if (k-- > 0)
                    c = ch[p[0]];
            }
            else if (c == p[1]) {
                if (k-- > 0)
                    c = ch[p[1]];
            }
            if (c == 'N') x--;
            if (c == 'S') x++;
            if (c == 'W') y--;
            if (c == 'E') y++;
            ans = max(abs(x)+abs(y), ans);
        }
        return ans;
    }

    int maxDistance(string s, int k) {
        // goal: find the max distance that we can change at most k
        // idea:
        // dp, ending index i, pos (x,y), used j operations
        // dp[i][x][y][j]

        // greedy,
        // k=0
        // k=1, erase east
        // ....
        // k=n, erase north
        // we can only erase one direction
        // and change vertical or orization

        // wrong, it can have greater value in middle
        // so ...
        // we need to care this
        // [    ]

        // only two case in previous?
        // change W -> change S
        // change S -> change W

        // we not actually change the direction...

        // check hint:
        // only 4 combinations
        // NE, NW, SE, SW
        
        vector<string> pos = {"NE", "NW", "SE", "SW"};
        int ans = 0;
        for (auto &p: pos) {
            ans = max(ans, change(p, s, k));
        }
        return ans;
    }
};
