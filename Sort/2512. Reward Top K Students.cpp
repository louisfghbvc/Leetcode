class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        // goal: return top k students
        // idea: sort by score, lower id
        
        // convert the positive feedback to hashset
        
        vector<pair<int, int>> arr;
        unordered_set<string> good(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> bad(negative_feedback.begin(), negative_feedback.end());
        
        for (int i = 0; i < report.size(); ++i) {
            int score = 0;
            stringstream ss(report[i]);
            string s;
            while (ss >> s) {
                if (good.count(s)) score += 3;
                else if (bad.count(s)) score -= 1;
            }
            arr.push_back({-score, student_id[i]});
        }
        
            
        sort(arr.begin(), arr.end());
    
        
        // output
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(arr[i].second);
        return ans;
    }
};
