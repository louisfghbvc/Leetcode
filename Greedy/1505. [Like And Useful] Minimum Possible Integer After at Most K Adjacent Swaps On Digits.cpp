// Magic prefix sum...
// make use array to bit tree.
// try to find min value count that smaller than k swaps
// after find value, the index+1, count--, means the after index swap substract one.
// O(NlogN)

class Solution {
    struct BIT{
        int N;
        vector<int> data;
        BIT(int n){
            N = n;
            data.resize(n+1);
        }    
        void update(int x, int val){
            for(; x <= N; x += x&-x) data[x] += val;
        }
        int sum(int x){
            int res = 0;
            for(; x > 0; x -= x&-x) res += data[x];
            return res;
        }
    };
public:
    string minInteger(string &num, int k) {
        int n = num.size();
        string res;
        BIT bt(n);
        for(int i = 1; i <= n; ++i) bt.update(i, 1);
        
        queue<int> q[10];
        for(int i = 0; i < n; ++i){
            q[num[i]-'0'].push(i);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 10; ++j){
                if(!q[j].empty()){
                    int idx = q[j].front(); 
                    int t = bt.sum(idx);
                    if(t <= k){
                        k -= t;
                        res.push_back(j+'0');
                        bt.update(idx+1, -1);
                        q[j].pop();
                        break;
                    }
                }
                
            }
        }
        
        return res;
    }
};
