//16ms 10.4MB
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto &c : moves){
            switch(c){
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y--;
                    break;
                case 'D':
                    y++;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};
