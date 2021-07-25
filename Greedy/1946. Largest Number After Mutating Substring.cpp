// Greedy find largest, and from that index do change.

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        int i;
        for(i = 0; i < num.size(); ++i){
            if(change[num[i] - '0'] > num[i] - '0') break;
        }
        while(i < num.size() && change[num[i] - '0'] >= num[i] - '0'){
            num[i] = change[num[i] - '0'] + '0';
            i++;
        }
        return num;
    }
};
