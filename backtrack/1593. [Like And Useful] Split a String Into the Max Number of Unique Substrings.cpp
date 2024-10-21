// just BruteForce. but I stick with the cut to 2 string.
// autcually just cut left. and other go to recursive, same as cut 2.
// still noob. sad.

class Solution {
public:
    int maxUniqueSplit(string s) {
        // goal: split the string into substring such that each string is unique
        // idea:
        // abc => length 1 has 26
        // length 2 has 
        // lets try all possible.
        // dfs => each letter we can used or not
        // when split => check out current string if in the set or not

        unordered_set<string> vis;
        int ans = 0;
        auto dfs = [&](auto& self, int i, int split) -> void {
            if (i >= s.size()) {
                ans = max(ans, split);
                return;
            }

            string tmp;
            for (int j = i; j < s.size(); ++j) {
                // used
                tmp += s[j];
                // split
                if (!vis.count(tmp)) {
                    vis.insert(tmp);
                    self(self, j+1, split+1);
                    vis.erase(tmp);
                }
            }

        };
        dfs(dfs, 0, 0);

        return ans;
    }
};
