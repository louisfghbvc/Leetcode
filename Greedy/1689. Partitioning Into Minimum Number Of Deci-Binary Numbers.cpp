// just max digit. because no matter how. always need largest bit.
// O(N).
class Solution {
public:
    int minPartitions(string n) {
        int b = 0;
        for(char c: n){
            b = max(b, c-'0');
        }
        return b;
    }
};
