// Segment tree. Divide and Conquer. O(NlogN)
// each add minimum. and left part and right part. update val
// val means already build.

class Solution {
public:
    vector<int> tre;
    vector<int> arr;
    int n;
    
    void build(int id, int l, int r){
        if(l == r){
            tre[id] = l;
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = (arr[tre[id*2]] <= arr[tre[id*2+1]]) ? tre[id*2] : tre[id*2+1]; 
    }
    
    int query(int id, int l, int r, int x, int y){
        if(r < x || l > y) return -1;
        if(l >= x && r <= y) return tre[id];
        int mid = (l+r)/2;
        int left = query(id*2, l, mid, x, y);
        int right = query(id*2+1, mid+1, r, x, y);
        if(left == -1) return right;
        if(right == -1) return left;
        return (arr[left] <= arr[right]) ? left : right;
    }
    
    int help(int l, int r, int val){
        if(l > r) return 0;
        int mid = query(1, 0, n-1, l, r);
        int mn = arr[mid];
        return mn - val + help(l, mid-1, mn) + help(mid+1, r, mn);
    }
    
    int minNumberOperations(vector<int>& target) {
        n = target.size();
        arr = target;
        tre = vector<int>(4*n+5);
        build(1, 0, n-1);
        return help(0, n-1, 0);
    }
};


// O(N). diff array.
// like wall only build left wall.
// so just compare prev wall is big than prev. then add diff.
// otherwise. small than prev. no need to add.
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for(int i = 1; i < target.size(); ++i) ans += max(0, target[i] - target[i-1]);
        return ans;
    }
};
