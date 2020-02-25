//0ms 8.3Mb
class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); ++i){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
        }
        return str;
    }
};
