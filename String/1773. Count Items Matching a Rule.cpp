// O(N). Too simple.
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for(auto &r: items){
            string type = r[0], color = r[1], name = r[2];
            if(ruleKey == "type" && ruleValue == type) cnt++;
            else if(ruleKey == "color" && ruleValue == color) cnt++;
            else if(ruleKey == "name" && ruleValue == name) cnt++;
        }
        return cnt;
    }
};
