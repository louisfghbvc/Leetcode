// use one param as stack.
// O(N).
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int lv = 0;
        for(auto&s: logs){
            if(s == "../") lv = max(0, lv-1);
            else if(s == "./");
            else lv++;
        }
        return lv;
    }
};
