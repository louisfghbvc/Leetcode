// power of 2 and (n-1)mod 3 == 0
// O(1)
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num&num-1) == 0 && (num-1)%3 == 0;
    }
};

// loop
class Solution {
public:
    bool isPowerOfFour(int num) {
        for(int i = 0; i <32; i+=2){
            if((num^(1<<i)) == 0) return true;
        }
        return false;
    }
};
