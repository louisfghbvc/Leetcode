class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ch = 0;
        for(int i = 0; i < bits.size(); ++i){
            if(bits[i] == 1 && (bits[i+1] == 0 || bits[i+1] == 1)){
                i++;
                ch = 1;
            }
            else ch = 0;
        }
        return !ch;
    }
};


//just check end. Tricky. odd one 
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int one = 0;
        for(int i = bits.size()-2; i >= 0 && bits[i]; --i) one++;
        return one%2 == 0;
    }
};
