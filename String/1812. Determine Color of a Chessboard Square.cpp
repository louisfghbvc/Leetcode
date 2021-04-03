// Parity. O(1)

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int j = coordinates[0] - 'a';
        int i = coordinates[1] - '0';
        return (i+j)%2 == 0;
    }
};
