// O(NlogN)
// Just Greedy. two params record break length.
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        //cout << s1 << " " << s2 << endl;
        int t = 0, t2 = 0;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] >= s2[i]){
                t++;
            }
            if(s1[i] <= s2[i]) t2++;
        }
        return t == s1.size() || t2 == s1.size();
    }
};
