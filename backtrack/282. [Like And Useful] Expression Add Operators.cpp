// Backtracking art !! Impressive.
// evaluate on the fly. prev only use in '*'

class Solution {
public:
    vector<string> res;
    string s;
    int target;
    
    void dfs(int i = 0, const string& tmp = "", long cur = 0, long prev = 0){
        if(i >= s.size()){
            if(cur == target) res.push_back(tmp);
            return;
        }
        long num = 0;
        string num_str = "";
        for(int j = i; j < s.size(); ++j){
            if(j > i && s[i] == '0') break; // leading zero
            num = num * 10 + s[j] - '0';
            num_str += s[j];
            if(i == 0){ // first
                dfs(j+1, num_str, num, num);
            }
            else{ // 3 case
                dfs(j+1, tmp + "*" + num_str, cur - prev + prev * num, prev * num); // 1*2*3
                dfs(j+1, tmp + "+" + num_str, cur + num, num);  // 1+2*3
                dfs(j+1, tmp + "-" + num_str, cur - num, -num); // 1-2*3
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        dfs();
        return res;
    }
};
