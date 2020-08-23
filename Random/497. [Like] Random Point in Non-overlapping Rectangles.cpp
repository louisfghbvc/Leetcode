 // make pick which randomly and uniformily, means the probability need to be all same
 // if A area is 70, B is 30 so the P must to 1/100. but if choose random A,B then choose point the P is 1/2*70%. so if 1/70*70% = 1% right? 
 // so thats why we use area to calculate.
 // Remeber add 1 because edge is include!!
 // why upper_bound. if rand(). 0 ~ 69. so means is in id 0. why because 0~69=70 area
 
class Solution {
public:
    map<int, int> mp;
    vector<vector<int>> R;
    int n, tot;
    Solution(vector<vector<int>>& rects) {
        R = rects;
        n = R.size();
        tot = 0;
        for(int i = 0; i < n; ++i){
            int area = (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            tot += area;
            mp[tot] = i;
        }
    }
    
    vector<int> pick() {
        int area = rand() % tot;
        auto it = mp.upper_bound(area);
        int id = it->second;
        auto &r = R[id]; 
        return {rand()%(r[2]-r[0]+1) + r[0], rand()%(r[3]-r[1]+1) + r[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
