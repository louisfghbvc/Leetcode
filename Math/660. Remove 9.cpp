// just convert base-10 to base-9
// O(logn), Is it really hard?

class Solution {
public:
    int newInteger(int n) {
        string res = "";
        while(n){
            res.push_back('0' + n % 9);
            n /= 9;
        }
        reverse(res.begin(), res.end());
        return stoi(res);
    }
};
