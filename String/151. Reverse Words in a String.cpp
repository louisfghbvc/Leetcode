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
