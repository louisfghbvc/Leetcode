// O(32*N). All case enum, use set to remove duplicate.
// Like Rolling dp.
// set size not n because is and. not or, so bit 1 always can be so clean.

class Solution {
public:
    
    int closestToTarget(vector<int>& arr, int target) {
        set<int> s;
        int ans = 1e9;
        for(int i = 0; i < arr.size(); ++i){
            set<int> ns;
            ns.insert(arr[i]);
            for(int x: s){
                ns.insert(x&arr[i]);
            }
            for(int x: ns){
                ans = min(ans, abs(x- target));
            }
            s = ns;
        }
        return ans;
    }
};
