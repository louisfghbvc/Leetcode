// Boring implement problem.

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> res;
        int n = keyName.size();
        map<string, vector<int>> mp;
        for(int i = 0; i < n; ++i) mp[keyName[i]].push_back(((keyTime[i][0]-'0')*10+keyTime[i][1]-'0')*60+((keyTime[i][3]-'0')*10+keyTime[i][4]-'0'));
        
        for(auto &[name, lst]: mp){
            sort(lst.begin(), lst.end());
            for(int i = 0; i+2 < lst.size(); ++i){
                if(lst[i+2] - lst[i] <= 60){
                    res.push_back(name);
                    break;
                }
            }
        }
        
        return res;
    }
};
