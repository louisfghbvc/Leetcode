// Priority_queue. O(nlogk).
// remember pq weak is top.


class Solution {
public:
    typedef pair<int, string> is;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> fre;
        for(auto &s: words) fre[s]++;
        
        auto cmp = [](is &a, is &b){
            return (a.first > b.first || a.first == b.first && a.second < b.second);
        };
        
        priority_queue<is, vector<is>, decltype(cmp)> pq(cmp);
        for(auto &[s, f]: fre){
            pq.push({f, s});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> res;
        while(pq.size()){
            res.push_back(pq.top().second); pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
