// Optimal. O(N). main idea is make pattern and word to a int.

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int p2i[26] = {};
        int n = pattern.size();
        
        unordered_map<string, int> w2i;
        istringstream iss(str);
        int i = 0;
        for(string word; iss >> word; ++i){
            if(i == n || p2i[pattern[i]-'a'] != w2i[word]) return false;  
            p2i[pattern[i]-'a'] = w2i[word] = i+1;
        }
        return i == n;
    }
};

// Simple two map
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        
        stringstream ss(str);
        vector<string> arr;
        while(ss >> str){
            arr.push_back(str);
        }
        
        int n = arr.size();
        if(pattern.size() != n) return false;
        for(int i = 0; i < n; ++i){
            char p = pattern[i];
            string str = arr[i];
            if(p2s.count(p)){
                if(p2s[p] != str)  return false;
            }
            else if(s2p.count(str)){
                if(s2p[str] != p) return false;
            }
            else{
                p2s[p] = str;
                s2p[str] = p;
            }
           
        }
        
        return true;
        
    }
};
