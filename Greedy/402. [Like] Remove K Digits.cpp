// Greedy. find first decreasing digit. then Recursive.
// O(k*n). 20ms. 10.1MB
class Solution {
public:
    string removeKdigits(string &num, int k) {
        if(k == 0) return num;
        int id = 0;
        for(; id < num.size()-1; ++id){
            if(num[id] > num[id+1]){
                break;    
            }
        }
        if(num.size() > 0) num.erase(num.begin()+id);
        while(num.size() > 1 && num[0] == '0')  num.erase(num.begin());
        if(num.size() == 0) num = "0";
        return removeKdigits(num, k-1);
    }
};

// Solution2 Optimal. 8ms. O(k*n). One pass.
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char c : num){
            while(ans.size() && ans.back() > c && k){
                ans.pop_back();
                k--;
            }
            if(!ans.size() && c == '0') continue;
            ans.push_back(c);
        }
        while(ans.size() && k--) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};
