// if go back to origin, must cycle. or direction change.
// O(N).

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        for(char c: instructions){
            if(c == 'L') dir--;
            else if(c == 'R') dir++;
            else{
                if(dir == 0){
                    y++;
                }
                else if(dir == 1){
                    x++;
                }
                else if(dir == 2){
                    y--;
                }
                else{
                    x--;
                }
            }
            dir = (dir+4)%4;
        }
        return (x == 0 && y == 0) || dir > 0;
    }
};
