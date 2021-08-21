// cur to prev, prev to cur. remember to + 26.
class Solution {
public:
    int minTimeToType(string word) {
        int d = 0;
        int res = word.size();
        for(char c: word){
            int curd = c - 'a';
            res += min({abs(curd - d), abs(d + 26-curd), abs(26-d + curd)});
            d = curd;
        }
        return res;
    }
};
