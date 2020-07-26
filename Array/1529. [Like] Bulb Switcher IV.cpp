// Trick, Like greedy.
// if left from right.
// we just need to cnt how many different.
// 011101 is same as 0101
// and ans is 3.
// O(N)

class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        char val = '0';
        for(auto c: target){
            if(val != c){
                val = c;
                cnt++;
            }
        }
        return  cnt;
    }
};
