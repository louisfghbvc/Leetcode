// a lots of memory copy...
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
    vector<int> dp[35][35]; // in C++, dp use set is very slow... due to copy and paste
    string s; 
};

////////////////////////////////////// use pointer and reference, super fast.
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
    
    unordered_set<int> &dfs(int l, int r){ // use pointer tricky
        auto *res = &dp[l][r];
        if(res->size()) return dp[l][r];
        if(l == r){
            res->insert(s[l] - '0');
            return dp[l][r];
        }
        
        for(int j = l; j <= r; j++){
            if(s[j] == '+' || s[j] == '*'){
                auto *left = &dfs(l, j-1);
                auto *right = &dfs(j+1, r);
                for(auto &a: *left)
                    for(auto &b: *right){
                        int put = s[j] == '+' ? a+b : a*b;
                        if(put > 1000) continue;
                        res->insert(put);
                    }
            }
        }

        return dp[l][r];
    }
    
    int scoreOfStudents(string s, vector<int>& answers) {
        this->s = s;
        int correct = compute(postfix(s));
        auto *possible = &dfs(0, s.size()-1);
        
        int score = 0;
        for(int x: answers){
            if(x == correct) score += 5;
            else if(possible->count(x)) score += 2;
        }
        return score;
    }
    
private:
    unordered_set<int> dp[35][35];
    string s; 
};

////////////////////////////////////// only use pointer, not reference. more concise. and just use stack cal ans
class Solution {    
public:    
    unordered_set<int> *dfs(int l, int r){
        auto *res = &dp[l][r];
        if(res->size()) return res;
        if(l == r){
            res->insert(s[l] - '0');
            return res;
        }
        
        for(int j = l; j <= r; j++){
            if(s[j] == '+' || s[j] == '*'){
                auto *left = dfs(l, j-1);
                auto *right = dfs(j+1, r);
                for(auto &a: *left)
                    for(auto &b: *right){
                        int put = s[j] == '+' ? a+b : a*b;
                        if(put > 1000) continue;
                        res->insert(put);
                    }
            }
        }

        return res;
    }
    
    int scoreOfStudents(string s, vector<int>& answers) {
        this->s = s;
        int correct = 0;
        stack<int> stk;
        stk.push(s[0] - '0');
        for(int i = 2; i < s.size(); i += 2){
            if(s[i-1] == '*'){ // only do mul
                int top = stk.top(); stk.pop();
                top *= (s[i]-'0');
                stk.push(top);
            }
            else{
                stk.push(s[i]-'0');
            }
        }
        while(stk.size()){
            correct += stk.top(); stk.pop();
        }
        auto *possible = dfs(0, s.size()-1);
        
        int score = 0;
        for(int x: answers){
            if(x == correct) score += 5;
            else if(possible->count(x)) score += 2;
        }
        return score;
    }
    
private:
    unordered_set<int> dp[35][35];
    string s; 
};

// python use eval, and memo is concise and clean.
