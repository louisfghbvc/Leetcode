// first calculate each char occur. left, right
// each char, must fit definition, contain all occur.
// think about abab, a: 0~2, b: 1~3
// so only case is 0~3. that's why only start == left[i].
// aba is not fit. because b all occur not contain
// after this.
// interval schedal problem.
// why sort end first ?
// because start first may not be optimal, since the interval is so long.
// so sort by end first.
// and try to get non overlap.
// O(26*N)


class Solution {
typedef pair<int, int> ii;
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> left(26, INT_MAX);
        vector<int> right(26, -1);
        
        for(int i = 0; i < n; ++i){
            int c = s[i]-'a';
            left[c] = min(left[c], i);
            right[c] = max(right[c], i);
        }
        
        vector<ii> arr;
        for(int i = 0; i < 26; ++i){
            int start = left[i];
            int end = right[i];
            for(int j = start; j <= end; ++j){
                int c = s[j]-'a';
                start = min(left[c], start);
                end = max(right[c], end);
            }
            if(start < n && start == left[i]){
                arr.push_back({end, start});
            }
        }
        
        sort(arr.begin(), arr.end());
        int prev = -1;
        vector<string> ans;
        for(auto &[end, start]: arr){
            if(start > prev){
                ans.push_back(s.substr(start, end-start+1));
                prev = end;
            }
        }
        return ans;
    }
};
