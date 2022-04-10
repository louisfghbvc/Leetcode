class Solution {
public:
    string minimizeResult(string expression) {
        // goal: <num1>+<num2>, only have one +
        // add parentheses, try to add left in all possible, and right in all possible
        // 247+38
        // (247 or 2(47 or 24(7  247(
        // 38) or +3)8
        
        int pos = expression.find('+');
        
        // left, use vector<pair<int, int>> -> product, value 
        vector<pair<int, int>> left, right;
        for (int i = 0; i < pos; ++i) {
            if (i == 0) {
                left.push_back({-1, stoi(expression.substr(0, pos))});
            }
            else {
                left.push_back({stoi(expression.substr(0, i)), stoi(expression.substr(i, pos-i))});
            }
        }
        
        // right
        for (int i = pos+1; i < expression.size(); ++i) {
            if (i+1 == expression.size()) {
                right.push_back({-1, stoi(expression.substr(pos+1))});
            }
            else {
                right.push_back({stoi(expression.substr(i+1)), stoi(expression.substr(pos+1, i-pos))});
            }
        }
        
        string res = "";
        int mn = INT_MAX;
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                int val = abs(left[i].first) * (left[i].second + right[j].second) * abs(right[j].first);
                if (val < mn) {
                    mn = val;
                    string tmp = "";
                    if (left[i].first == -1) {
                        tmp = "(" + to_string(left[i].second);
                    }
                    else {
                        tmp = to_string(left[i].first) + "(" + to_string(left[i].second);
                    }
                    tmp += "+";
                    if (right[j].first == -1) {
                        tmp += to_string(right[j].second) + ")";
                    }
                    else {
                        tmp += to_string(right[j].second) + ")" + to_string(right[j].first);
                    }
                    res = tmp;
                }
            }
        }
        
        return res;
    }
};
