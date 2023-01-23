class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // goal: sort by kth score
        // idea: sort each col by larget to smallest
        // and sort row
        

        sort(score.begin(), score.end(), [&](auto &a, auto &b){
            return a[k] > b[k];
        });
    
        
        return score;
    }
};
