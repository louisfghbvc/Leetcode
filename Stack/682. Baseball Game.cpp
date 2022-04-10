class Solution {
public:
    int calPoints(vector<string>& ops) {
        // goal: calculate sum of all scores
        // simulate
        
        vector<int> record;
        for (auto &s: ops) {
            if (s == "+") {
                int a = record.back();
                int b = record[record.size()-2];
                record.push_back(a+b);
            }
            else if (s == "D") {
                record.push_back(2*record.back());
            }
            else if (s == "C") {
                record.pop_back();
            }
            else {
                record.push_back(stoi(s));
            }
        }
        
        return accumulate(record.begin(), record.end(), 0);
    }
};
