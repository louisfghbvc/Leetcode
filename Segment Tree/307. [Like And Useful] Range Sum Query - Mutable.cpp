// Bit indexed tree. need index from 1. Simple and useful.
// O(NlogN).
class NumArray {
public:
    vector<int> tre;
    vector<int> data;
    int n;
    
    void updateT(int i, int x){
        for( ; i <= n; i += i&-i){
            tre[i] += x;
        }
    }
    
    int sum(int i){
        int res = 0;
        for( ; i > 0; i -= i&-i){
            res += tre[i];
        }
        return res;
    }
    
    NumArray(vector<int>& nums) {
        data = nums;
        n = nums.size();
        tre.resize(n+1);
        for(int i = 1; i <= n; ++i) updateT(i, nums[i-1]);
    }
    
    void update(int i, int val) {
        int d = val - data[i];
        data[i] = val;
        updateT(i+1, d);
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

// Segment tree, Divide and Conquer
// O(NlogN).

class NumArray {
public:
    vector<int> tre;
    vector<int> arr;
    int n;
    
    void build(int id, int l, int r){
        if(l > r) return;
        if(l == r){
            tre[id] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = tre[id*2] + tre[id*2+1];
    }
    
    void updateT(int id, int l, int r, int pos, int x){
        if(l == pos && r == pos){
            tre[id] = x;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) updateT(id*2, l, mid, pos, x);
        else updateT(id*2+1, mid+1, r, pos, x);
        tre[id] = tre[id*2] + tre[id*2+1];
    }
    
    int query(int id, int l, int r, int ll, int rr){
        if(l > rr || r < ll) return 0;
        if(r <= rr && l >= ll) return tre[id];
        int mid = (l+r)/2;
        int left = query(id*2, l, mid, ll, rr);
        int right = query(id*2+1, mid+1, r, ll, rr);
        return left+right;
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        tre.resize(4*n+5);
        build(1, 0, n-1);
    }
    
    void update(int i, int val) {
        updateT(1, 0, n-1, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
};
