// O(N). tricky. use monotonic stack
// record smallest string.

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        int n = s.size();
        
        int cnt = 0;
        for(char c: s) 
            cnt += c == letter; 
        
        string t = "";
        int cur = 0;
        for(int i = 0; i < n; ++i){
            while(t.size() && t.back() > s[i] && t.size()-1 + n-i >= k){ // enough string, can pop
                if(t.back() == letter){
                    if(cur-1 + cnt < rep) break; // if no enough letter
                }
                cur -= t.back() == letter;
                t.pop_back();
            }
            if(t.size() < k || cur < rep){
                cur += s[i] == letter;
                t.push_back(s[i]);
            }
            cnt -= s[i] == letter; // remain letter
        }
        
        // the t will be increasing, and we just choose leftmost.
        // e.g t=aabbb, k=3, letter=b, res=abb
        int get = k - rep;
        string res = "";
        for(char c: t){
            if(c == letter){
                res += letter;
            }
            else if(get > 0){ 
                get--;
                res += c;
            }
        }
        
        return res;
    }
};

// Just one pass, O(N) use stack, awesome clean
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        int n = s.size();
        int cnt = count(s.begin(), s.end(), letter);

        string res = "";
        for(int i = 0; i < n; ++i){
            while(res.size() && res.back() > s[i] && res.size()-1 + n-i >= k){
                if(res.back() == letter && cnt <= rep) break; // no enough
                rep += res.back() == letter;
                res.pop_back();
            }
            
            if(res.size() < k){
                if(s[i] == letter){
                    res.push_back(s[i]);
                    rep--;
                }
                else if(k - (int)res.size() > rep){ // make sure enough
                    res.push_back(s[i]);
                }
            }
            
            cnt -= s[i] == letter;
        }
        
        return res;
    }
};


// Solution2 index array, tricky. impressive
// each position enumerate all 'a' to 'z'
// check 3 case
// 1: cur pos > prev pos
// 2: enough chars to get size k
// 3: enough letter
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        int n = s.size();
        vector<int> rem(n); // suffix array, suf[i]: i+1~
        for(int i = n-2; i >= 0; --i)
            rem[i] = rem[i+1] + (s[i+1] == letter);
        
        vector<queue<int>> ind(26);
        for(int i = 0; i < n; ++i)
            ind[s[i]-'a'].push(i);
        
        string res = "";
        int last = -1;
        
        // 3 case
        // 1: cur pos > prev pos
        // 2: enough chars to get size k
        // 3: enough letter
        for(int i = 0; i < k; ++i){
            // 'a' - 'z'
            for(int j = 0; j < 26; ++j){
                // case1
                while(ind[j].size() && ind[j].front() < last) ind[j].pop();
                
                int need = (j == letter-'a') ? rep-1 : rep;
                // case2 & case3
                if(ind[j].size() && rem[ind[j].front()] >= need && k-i > need && n-ind[j].front() >= k-i){
                    res.push_back('a' + j);
                    rep -= j == letter - 'a';
                    last = ind[j].front(); ind[j].pop();
                    break;
                }
            }
        }
        
        return res;
    }
};

