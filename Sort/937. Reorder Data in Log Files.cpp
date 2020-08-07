// O(NlogN). WA 3 times...
// Nothing Special. problem is long.
class Solution {
public:
    typedef pair<string, string> ps;
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<ps> let;
        vector<string> dg;
        for(auto &log: logs){
            int i;
            for(i = 0; i < log.size(); ++i) if(log[i] == ' ') break;
            bool f = isdigit(log[i+1]);
            if(!f){
                string a = log.substr(0, i);
                string b = log.substr(i);
                let.push_back({a, b});
            }
            else{
                dg.push_back(log);
            }
        }
        sort(let.begin(), let.end(), [](ps &a, ps&b){
           return (a.second == b.second && a.first < b.first) || a.second < b.second; 
        });
        for(auto &x: let){
            res.push_back(x.first + x.second);
        }
        for(auto &x: dg){
            res.push_back(x);
        }
        return res;
    }
};
