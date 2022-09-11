class Solution {
public:
    int partitionString(string s) {
        // goal: find the minimum partition such that each group only has one letter
        // idea: use the hashset
        // two pointers
        
        int group = 1;
        unordered_set<char> vis;
        for (char c: s) {
            if (vis.count(c)) {
                vis.clear();
                group++;
            }
            vis.insert(c);
        }
        
        return group;
    }
};
