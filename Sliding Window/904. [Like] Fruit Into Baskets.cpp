// O(N). Autually no need queue. First.
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        unordered_map<int, int> mp;
        queue<int> q;
        for(int r = 0; r < tree.size(); ++r){
            q.push(tree[r]);
            ++mp[tree[r]];
            while(mp.size() > 2 && q.size()){
                int x = q.front(); q.pop();
                if(--mp[x] == 0) mp.erase(x);
            }
            res = max((int)q.size(), res);
        }
        
        return res;
    }
};

// O(N). two pointer, sliding window.
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int r = 0, l = 0; r < tree.size(); ++r){
            ++mp[tree[r]];
            while(mp.size() > 2){
                if(--mp[tree[l]] == 0) mp.erase(tree[l]);
                l++;
            }
            res = max(r-l+1, res);
        }
        
        return res;
    }
};
