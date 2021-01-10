// OMG. Almost... done. just keep index to union. not the value.
// index is unique. but value is not.
// after merge. group A.
// and search B[i] is in or not
// O(N).
class Solution {
public:
    int p[100005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        int xs = -p[x], ys = -p[y];
        if(xs < ys) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
    int minimumHammingDistance(vector<int>& A, vector<int>& B, vector<vector<int>>& edge) {
        memset(p, -1, sizeof p);
        
        for(auto &e : edge){
            uni(e[0], e[1]);
        }
        
        vector<unordered_multiset<int>> cyc(A.size());
        for(int i = 0; i < A.size(); ++i){
            if(A[i] != B[i]) cyc[find(i)].insert(A[i]);
        }
        
        int res = 0;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] == B[i]) continue;
            auto &tmp = cyc[find(i)];
            auto p = tmp.find(B[i]);
            if(p != tmp.end()){
                tmp.erase(p);
            }
            else res++;
        }
        
        return res;
    }
};
