// O(M+N), Counting sort. Count magazine, and --ransomNote 
static int fast = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 1;
}();
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int fre[26] = {};
        for(const auto &c : magazine){
            fre[c-'a']++;
        }
        for(const auto &c : ransomNote){
            if(--fre[c-'a'] < 0) return 0;
        }
        return 1;
    }
};
