// BF. O(?). bound is small.

class Solution {
public:
    long long minimumPerimeter(long long bound) {
        long res = 0;
        long prev = 0, p = 1;
        long tot = 0;
        long sub = 0;
        for(long layer = 3; ; layer += 2){
            long node = layer - 1;
            long side = prev + p + 2L*node;
            tot += side;
            sub += node;
            if(tot * 4 - sub * 4 >= bound){
                return node * 4;
            }
            p = layer;
            prev = side;
        }
        
        return -1;
    }
};

// BS. formula
