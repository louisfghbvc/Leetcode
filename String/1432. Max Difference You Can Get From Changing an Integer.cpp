// Just Enumerate
class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;
        int mx = num, mn = INT_MAX;
        for(int i = 0; i < a.size(); ++i){
            char x = a[i];
            for(char d = '0'; d <= '9'; ++d){
                string t = a;
                for(int j = 0; j < a.size(); ++j){
                    if(!j && d == '0' && t[j] == x) break;
                    if(t[j] == x) t[j] = d;
                }
                mx = max(stoi(t), mx);
            }
        }
        for(int i = 0; i < b.size(); ++i){
            char x = b[i];
            for(char d = '0'; d <= '9'; ++d){
                string t = b;
                for(int j = 0; j < b.size(); ++j){
                    if(!j && d == '0' && t[j] == x) break;
                    if(t[j] == x) t[j] = d;
                } 
                mn = min(stoi(t), mn);
            }
           
        }
        //cout << mx << " " << mn << endl;
        return mx - mn;
    }
};
