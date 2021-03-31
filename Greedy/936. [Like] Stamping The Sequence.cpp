// Hard to think. so fill '.' so that prefix no influence.
// O(NM). fill big to small

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size();
        int n = target.size();
        
        bool matched;
        vector<int> res;
        do{
            matched = false;
            for(int i = 0; i+m-1 < n; ++i){
                bool ok = true;
                int dot = 0;
                for(int j = 0; j < m; ++j){
                    if(target[i+j] == '.') dot++;
                    
                    if(target[i+j] != '.' && target[i+j] != stamp[j]){
                        ok = false;
                        break;
                    }
                }
                if(ok && dot < m){
                    res.push_back(i);
                    matched = true;
                    fill(target.begin() + i, target.begin() + i + m, '.');
                }
            }
        }while(matched);
        
        for(char c: target) if(c != '.') return {};
        
        reverse(res.begin(), res.end());
        return res;
    }
};
