class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string x;
        int prev = -1;
        while(ss >> x){
            if(isdigit(x[0])){
                int n = stoi(x);
                if(n <= prev) return false;
                prev = n;
            }
        }
        return true;
    }
};
