// O(N), use counting sort
// 36ms, 10.7MB
static int fast = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 1;
}();
class Solution {
public:
    int firstUniqChar(string s) {
        int fre[26] = {};
        for(const auto& c: s) fre[c-'a']++;
        for(int i = 0; i < s.size(); ++i){
            if(fre[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
