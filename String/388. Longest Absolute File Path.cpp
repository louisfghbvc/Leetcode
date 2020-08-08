// just a map use and one item from item.
// like prefix. and check some edge case.
// O(N).

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size(), res = 0;
        map<int, int> mp;
        int t = 0;
        bool ex = 0;
        int level = 0;
        
        for(int i = 0; i < n; ++i){
            if(input[i] == '\n');
            else if(input[i] == '\t') level++;
            else{
                while(i < n && (input[i] != '\t' && input[i] != '\n')){
                    i++; t++;
                    if(input[i] == '.') ex = 1;
                }
                mp[level] = mp[level-1]+t+1;
                if(ex){
                    res = max(res, mp[level]);
                }
                ex = 0; t = 0;
                level = 0;
            }
        }
        return res > 0 ? res-1 : 0;
    }
};
