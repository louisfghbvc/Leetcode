class Solution {    
    
public:
    int order(char c){
        if(c == '+') return 1;
        return 2;
    }
    
    string postfix(string &s){
        string res = "";
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])) res += s[i];
            else{
                while(st.size() && order(st.top()) >= order(s[i])){
                    res += st.top(); st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size()){
            res += st.top(); st.pop();
        }
        return res;
    }
    
    int compute(const string& s){
        int res = 0;
        stack<int> st;
        for(char c: s){
            if(isdigit(c)) st.push(c-'0');
            else{
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(c == '+') st.push(a+b);
                else st.push(a*b);
            }
        }
        return st.top();
    }
    
    vector<int> dfs(int l, int r){
        if(l == r) return {s[l] - '0'};
        if(dp[l][r].size()) return dp[l][r];
        
        vector<int> res;
        // enumerate all operator
        for(int j = l; j+1 <= r; j += 2){ // speed up.
            if(s[j+1] == '+' || s[j+1] == '*'){
                auto left = dfs(l, j);
                auto right = dfs(j+2, r);
                for(auto &a: left)
                    for(auto &b: right){
                        int put = s[j+1] == '+' ? a+b : a*b;
                        if(put > 1000) continue;
                        res.push_back(put);
                    }
            }
        }
        
        unordered_set<int> tmp(res.begin(), res.end());
        return dp[l][r] = vector<int>(tmp.begin(), tmp.end());
    }
    
    int scoreOfStudents(string s, vector<int>& answers) {
        this->s = s;
        int correct = compute(postfix(s));
        auto possible = dfs(0, s.size()-1);
        unordered_set<int> st(possible.begin(), possible.end());
        
        int score = 0;
        for(int x: answers){
            if(x == correct) score += 5;
            else if(st.count(x)) score += 2;
        }
        return score;
    }
    
private:
    vector<int> dp[35][35]; // in C++, dp use set is very slow...
    string s; 
};


// python use eval, and memo is concise and clean.
