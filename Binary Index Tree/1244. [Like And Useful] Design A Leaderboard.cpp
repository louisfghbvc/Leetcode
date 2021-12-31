// search top k value use BIT

class Leaderboard {
    struct BIT{
        vector<int> sum, cnt;
        int n;
        BIT(int _n) : n(_n+1) {
            sum.resize(n);
            cnt.resize(n);
        }
        void add(int x, int val, int c){
            if(x < 1) return;
            for(; x <= n; x += x&-x){
                sum[x] += val;
                cnt[x] += c;
            }
        }
        pair<int, int> query(int x){
            if(x < 1) return {0, 0};
            int res = 0, cc = 0;
            for(; x; x -= x&-x){
                res += sum[x];
                cc += cnt[x];
            }
            return {res, cc};
        }
        pair<int, int> query(int l, int r){
            auto a = query(r);
            auto b = query(l-1);
            return make_pair(a.first - b.first, a.second - b.second);
        }
        int TopK(int k){
            int l = 0, r = n-1;
            while(l <= r){
                int mid = (l+r)/2;
                auto p = query(mid, n-1);
                if(p.second >= k) l = mid+1;
                else r = mid-1;
            }
            return r;
        }
    };
    
    
public:
    Leaderboard() {
        bit = new BIT(MAX);    
    }
    
    void addScore(int playerId, int score) {
        if(!mp.count(playerId)){
            bit->add(score, score, 1);
            mp[playerId] = score;
        }
        else{
            int &ori = mp[playerId];
            bit->add(ori, -ori, -1);
            ori += score;
            bit->add(ori, ori, 1);
        }
    }
    
    int top(int K) {
        int val = bit->TopK(K);
        auto q = bit->query(val+1, MAX);
        K -= q.second;
        return q.first + val * K;
    }
    
    void reset(int playerId) {
        int &ori = mp[playerId];
        bit->add(ori, -ori, -1);
        ori = 0;
    }
    
private:
    unordered_map<int, int> mp;
    BIT* bit;
    const int MAX = 1e5+5;
};
