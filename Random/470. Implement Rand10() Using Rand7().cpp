// Reject Sampling
// so rand7()*rand7() = 1~49. p=1/49
// we need p = 1/10. so 10/40

class Solution {
public:
    int rand10() {
        int row, col, idx;
        do{
            row = rand7();
            col = rand7();
            idx = (row-1)*7+col;
        }while(idx > 40);
        return (idx-1)%10+1;
    }
};
