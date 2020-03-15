//0ms 7.5MB
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        for(int i = 0, j = 0; i < name.size(); ++i){
            char c = name[i]; int fre = 1;
            while(i + 1 < name.size() && name[i] == name[i+1]) fre++, i++;
            //cout << c << " ";
            int fre2 = 0;
            for(; j < typed.size() && c == typed[j]; j++, fre2++);
            //cout << fre2 << endl;
            if(fre2 < fre)
                return false;
        }
        return true;
    }
};
