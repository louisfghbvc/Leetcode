class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        if (count(suits.begin(), suits.end(), suits[0]) == 5)
            return "Flush";
        
        unordered_map<int, int> fre;
        for (int x: ranks) 
            fre[x]++;
        
        for (auto &[a, b]: fre) {
            if (b >= 3) {
                return "Three of a Kind";
            }
        }
        
        for (auto &[a, b]: fre) {
            if (b == 2) {
                return "Pair";
            }
        }
        
        return "High Card";
    }
};
