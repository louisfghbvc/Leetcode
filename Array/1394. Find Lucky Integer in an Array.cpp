class Solution {
public:
    int findLucky(vector<int>& arr) {
        int fre[505] = {};
        
        for(auto x: arr){
            fre[x]++;
        }
        for(int i = 500; i >= 1; --i){
            if(i == fre[i])
                return i;
        }
        return -1;
    }
};
