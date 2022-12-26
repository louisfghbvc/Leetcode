class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        // goal: find the closet target
        // idea: record all target index, and we have two directions
        // either left, right
        // calculate the minimum
        
        int ans = -1;
        int n = words.size();
        vector<int> ind;
        for (int i = 0; i < n; ++i)
            if (words[i] == target)
                ind.push_back(i);
        
        for (int i: ind) {
            if (ans == -1) {
                ans = min(n-abs(i - startIndex), abs(i - startIndex));
            }
            else {
                ans = min({ans, n-abs(i - startIndex), abs(i - startIndex)});
                
            }
        }
        
        return ans;
    }
};
