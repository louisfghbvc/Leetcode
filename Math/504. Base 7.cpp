// Recursive, Can be clean.
// O(log7N).
class Solution {
public:
    string convertToBase7(int num) {
        if(num < 0) return '-' + convertToBase7(-num);
        if(num < 7) return to_string(num);
        return convertToBase7(num/7) + to_string(num%7);
    }
};

// straight
class Solution {
public:
    string convertToBase7(int num) {
        if(num < 0) return '-' + convertToBase7(-num);
        if(!num) return "0";
        string res = "";
        while(num > 0){
            res.push_back(num%7+'0');
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
