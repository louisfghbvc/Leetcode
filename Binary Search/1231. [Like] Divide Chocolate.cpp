// O(NlogX), guess ans

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        // binary search
        
        // give u a sweetness, get k+1 pieces, and each is at least sweetness
        auto good = [&](int x){
            int num = 0;
            int piece = 0;
            for(int v: sweetness){
                piece += v;
                if(piece >= x){
                    num++;
                    piece = 0;
                }
            }
            return num > k;
        };
        
        int l = 0, r = accumulate(sweetness.begin(), sweetness.end(), 0);
        int ans = -1;
        while(l <= r){
            int mid = l+(r-l)/2; // avoid overflow
            if(good(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};
