// O(N). Use union to merge adjcent. when merge adjust the group size.
// use map to record group size.
class Solution {
public:
    int p[100005];
    unordered_map<int, int> mp;
    int find(int x){ 
        return p[x] <= 0 ? x : p[x] = find(p[x]); 
    }
    void uni(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(!p[px] || !p[py]) return;
        mp[-p[px]]--;
        mp[-p[py]]--;
        if(p[px] < p[py]){
            p[px] += p[py];
            p[py] = px;
            mp[-p[px]]++;
        }
        else{
            p[py] += p[px];
            p[px] = py;
            mp[-p[py]]++;
        }
    }
    int findLatestStep(vector<int>& arr, int m) {
        int res = -1;
        int n = arr.size();
        memset(p, 0, sizeof 0);
        for(int i = 1; i <= n; ++i){
            int pr = find(arr[i-1]);
            p[pr]--;
            // cout << "findp = " << pr << " p[pr] = " << p[pr] << "\n";
            mp[-p[pr]]++;
            uni(arr[i-1], arr[i-1]+1);
            uni(arr[i-1], arr[i-1]-1);
            if(mp[m] > 0) res = i;
        }
        return res;
    }
};
