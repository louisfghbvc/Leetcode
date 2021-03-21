// Count all candidate.
// O(logN).

class Solution {
public:
    int getFre(int x){
        int fre = 0;
        while(x){
            fre += (int)pow(10, x%10);
            x /= 10;
        }
        return fre;
    }
    bool reorderedPowerOf2(int N) {
        int can = 1;
        vector<int> all_can;
        for(; can <= 1e9; can *= 2){
            all_can.push_back(getFre(can));
        }
        int me = getFre(N);
        for(auto &c: all_can){
            if(me == c) return true;
        }
        return false;
    }
};


// use array.
class Solution {
public:
    vector<int> getFre(int x){
        vector<int> fre(10);
        while(x){
            fre[x % 10]++;
            x /= 10;
        }
        return fre;
    }
    bool reorderedPowerOf2(int N) {
        int can = 1;
        vector<vector<int>> all_can;
        for(; can <= 1e9; can *= 2){
            all_can.push_back(getFre(can));
        }
        vector<int> me = getFre(N);
        for(auto &c: all_can){
            if(me == c) return true;
        }
        return false;
    }
};
