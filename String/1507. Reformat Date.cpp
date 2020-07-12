// Use Sprintf more clean.

class Solution {
public:
    string reformatDate(string date) {
        string arr[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        stringstream ss(date);
        string dd, mm, yyyy;
        ss >> dd >> mm >> yyyy;
        int dlen = dd.size();
        int day = stoi(dd.substr(0, dlen-2));
        int m = 0;
        for(; m < 13; ++m){
            if(mm == arr[m]) break;
        }
        char str[256];
        sprintf(str, "%s-%02d-%02d", yyyy.c_str(), m, day);
        return string(str);
    }
};
