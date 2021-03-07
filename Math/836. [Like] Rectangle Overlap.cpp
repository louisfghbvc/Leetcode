// Math. if not overlap must be left or right or top or bottom side. update.
// De morgan
// O(1)
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // line must false
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
           rec2[0] == rec2[2] || rec2[1] == rec2[3]
          ) return false;
        
        return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2]
                || rec1[3] <= rec2[1] || rec1[1] >= rec2[3]
               );
    }
};

// Also can thought from 1D
// what if overlap in 1D
// [L1, R1] [L2, R2]
// L1 < R2 and L2 < R1
// so can upto 2D
