class Solution {
public:
    vector<int> p;
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        p[y] = x;
        return true;
    }

    int removeStones(vector<vector<int>>& stones) {
        // goal: find out the maximum stones we can remove
        // if we can remove only if we have another stone in same row/col

        // idea:
        // using union find?
        // each (x,y) looks as different root
        // for the group we always can add group size -1 -> wrong
        // we can find out the number of root!
        // the root cannot erase!
        // e.g
        //   1 2 3
        // 1 x o x
        // 2 o x o
        // 3 x x o

        unordered_map<int, int> xID, yID;
        int groups = 0;
        for (auto &s: stones) {
            if (!xID.count(s[0]))
                xID[s[0]] = groups++;
            if (!yID.count(s[1]))
                yID[s[1]] = groups++;
        }
        p.assign(groups, -1);
        for (auto &s: stones) {
            uni(xID[s[0]], yID[s[1]]);
        }
        
        int root = 0;
        for (int i = 0; i < groups; ++i)
            if (p[i] < 0)
                root++;

        return stones.size() - root;
    }
};
