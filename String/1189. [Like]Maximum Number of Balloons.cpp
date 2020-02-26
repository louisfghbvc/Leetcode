//0ms 9MB
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int fre[26] = {};
        for(int i = 0; i < text.size(); ++i){
            fre[text[i] - 'a']++;
        }
        return min({fre[0], fre[1], fre['n' - 'a'], fre['l' - 'a']/2, fre['o' - 'a']/2});
    }
};
