// Cuz need smallest lexico. so just update string from back.
// each compute how much can use. 
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        for(int i = n-1; i >= 0 && k > 0; --i){
            int need = k;
            if(need > 25) need = 25;
            res[i] = 'a' + need;
            k -= need;
        }
        return res;
    }
};
