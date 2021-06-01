// O(MlogM). Greedy.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) return false;
        map<int, int> mp;
        for(int x: hand) mp[x]++;
        
        for(auto &[x, f]: mp){
            if(f > 0){
                for(int i = 1; i < groupSize; ++i){
                    if(mp[x + i] < f)
                        return false;
                    else mp[x + i] -= f;
                }
            }
        }
        return true;
    }
};
