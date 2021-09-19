// Case check. O(N).

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto &s: operations){
            if(s[0] == '-' || s[2] == '-') x--;
            else x++;
        }
        return x;
    }
};
