//0ms 8.3MB
class Solution {
public:
    int dayfrom1971(string dt){
        int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y = stoi(dt.substr(0, 4)), m = stoi(dt.substr(5, 2)), d = stoi(dt.substr(8, 2));
        if(isleap(y))
            date[2] = 29;
        int sum = 0;
        for(int i = 1971; i < y; ++i){
            sum += isleap(i) ? 366 : 365;
        }
        for(int i = 1; i < m; ++i){
            sum += date[i];
        }
        return sum + d;
    }
    bool isleap(int x){
        return x % 4 == 0 && (x % 100 != 0 || x % 400 == 0);
    }
    int daysBetweenDates(string date1, string date2) {
        
        return abs(dayfrom1971(date1) - dayfrom1971(date2));
    }
};
