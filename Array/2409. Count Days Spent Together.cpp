class Solution {
public:
    
    vector<int> day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int conv(string &s) {
        int m = stoi(s.substr(0, 2)) - 1;
        int d = stoi(s.substr(3, 2));
        for (int i = 0; i < m; ++i)
            d += day[i];
        return d;
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
            
        int aL = conv(arriveAlice), aR = conv(leaveAlice);
        int bL = conv(arriveBob), bR = conv(leaveBob);        
        
        int cnt = 0;
        for (int i = 1; i <= 365; ++i) {
            if (aL <= i && i <= aR && bL <= i && i <= bR)
                cnt++;
        }
        return cnt;
    }
};
