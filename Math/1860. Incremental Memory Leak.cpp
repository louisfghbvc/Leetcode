class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        vector<int> res;
        for(int t = 1; ; ++t){
            if(m1 >= m2){
                if(m1 >= t) m1 -= t;
                else if(m2 >= t) m2 -= t;
                else return {t, m1, m2};
            }
            else{
                if(m2 >= t) m2 -= t;
                else if(m1 >= t) m1 -= t;
                else return {t, m1, m2};
            }
        }
        return res;
    }
};
