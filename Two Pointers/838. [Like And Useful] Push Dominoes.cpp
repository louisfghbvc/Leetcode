// Like trap the water. dp all left, and right postition. and when left. if R then enter L, lpos can not go.
// O(N).

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        if(!n) return "";
        
        vector<int> left(n), right(n);
        int lpos = left[0] = (dominoes[0] == 'R') ? 0 : n;
        for(int i = 1; i < n; ++i){
            if(dominoes[i] == 'R') lpos = -1;
            else if(dominoes[i] == 'L') lpos = n;
            lpos = left[i] = min(lpos+1, n);
        }
        
        int rpos = right[n-1] = (dominoes[n-1] == 'L') ? 0 : n;
        for(int i = n-2; i >= 0; --i){
            if(dominoes[i] == 'L') rpos = -1;
            else if(dominoes[i] == 'R') rpos = n;
            rpos = right[i] = min(rpos+1, n);
        }
        
        for(int i = 0; i < n; ++i){
            if(dominoes[i] == '.'){
                if(left[i] < right[i]) dominoes[i] = 'R';
                else if(left[i] > right[i]) dominoes[i] = 'L';
            }
        }
        
        return dominoes;
    }
};
