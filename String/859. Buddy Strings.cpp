// O(N). O(1). just enum case.
// so just calculate different position. 

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n = A.size();
        if(n != B.size()) return false;
        int cntA[26] = {};
        vector<int> dif;
        for(int i = 0; i < n; ++i){
            cntA[A[i]-'a']++;
            if(A[i] != B[i]) dif.push_back(i);
        }
        if(dif.empty()){
            for(int i = 0; i < 26; ++i) if(cntA[i] >= 2) return true;
        }
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
    }
};
