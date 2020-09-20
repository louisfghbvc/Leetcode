// two pass, easy to code.
// just simulate.

class Solution {
public:
    string reorderSpaces(string text) {
        int sp = 0;
        stringstream ss(text);
        string str;
        vector<string> arr;
        while(ss >> str) arr.push_back(str);
        
        for(char c: text){
            if(c == ' ') sp++;
        }
        if(arr.size() == 1){
            return arr[0] + string(sp, ' ');
        }
        
        int divide = sp/(arr.size()-1);
        int re = sp%(arr.size()-1);
        
        string res = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; ++i){
            res += string(divide, ' ') + arr[i];
        }
        return res + string(re, ' ');
    }
};
