// Binary search the ans, O(logX(M+N)).
// split into pos, and neg, and then use two pointers 
// think each case
// 1 2 
// 3 5

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long> pos1, neg1, pos2, neg2;
        // split into two parts
        for(int x: nums1) 
            if(x >= 0) pos1.push_back(x);
            else neg1.push_back(x);
        for(int x: nums2) 
            if(x >= 0) pos2.push_back(x);
            else neg2.push_back(x);
        
        auto cal = [&](long x, vector<long> &a, vector<long> &b){
            long res = 0;
            int j = 0;
            for(int i = 0, j = 0; i < a.size(); ++i){
                while(j < b.size() && b[j] * a[i] <= x) j++;
                res += j;
            }
            return res;
        };
        
        auto check = [&](long x){
            long res = 0;
            
            // pos * pos
            for(int i = (int)pos2.size()-1, j = 0; i >= 0; --i){
                while(j < pos1.size() && pos1[j] * pos2[i] <= x) j++;
                res += j;
            }
            
            // neg * neg
            for(int i = 0, j = (int)neg1.size()-1; i < neg2.size(); ++i){
                while(j >= 0 && neg1[j] * neg2[i] <= x) --j;
                res += (int)neg1.size() - j - 1;
            }
            
            // pos neg
            res += cal(x, pos1, neg2) + cal(x, pos2, neg1);
            
            return res;
        };
        
        long ans = 0;
        long l = -1e10, r = 1e10;
        while(l <= r){
            long mid = (l + r)/2;
            if(check(mid) >= k){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
