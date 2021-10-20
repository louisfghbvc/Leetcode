// Boring. Just Reformat. Space O(N).
// O(1) can use user define func

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> arr;
        while(ss >> s){
            arr.push(s);
        }
        if(arr.empty()) return "";
        string res = arr.top(); arr.pop();
        while(arr.size()){
            res += " " + arr.top(); arr.pop();
        }
        return res;
    }
};


// O(N) Inplace
// reverse whole string
// reverse each string

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int storeIndex = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            if(storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while(j < s.size() && s[j] != ' ') s[storeIndex++] = s[j++];
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
            
        }
        
        s.erase(s.begin() + storeIndex, s.end());
        
        return s;
    }
};

// original 
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        for(int i = 0, j = 0; i < s.size(); i = j){
            while(i < s.size() && s[i] == ' ') i++;
            j = i;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j);
        }
        
        int index_fillin = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            else{
                while(i < s.size() && s[i] != ' ') s[index_fillin++] = s[i++];
                if(index_fillin < s.size())
                    s[index_fillin++] = ' ';
            }
        }
        
        while(s.size() > index_fillin || s.back() == ' ') s.pop_back();
        
        return s;
    }
};
