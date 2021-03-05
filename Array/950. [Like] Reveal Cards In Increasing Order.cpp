// Simulate trick. the process is just like queue.
// O(NlogN).

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        for(int i = 0; i < deck.size(); ++i){
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        for(int card: deck){
            int idx = q.front(); q.pop();
            res[idx] = card;
            if(!q.empty()){
                q.push(q.front()); q.pop();
            }
        }
        
        return res;
    }
};
