// So the trick is, two pass and get max.
// when two array same value then, choose max prefix. and give.
// O(M+N)

class Solution {
public:
    const int mod = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int m = 1e7+1;
        bool a[m] = {};
        bool b[m] = {};
        for(auto &v : nums1) a[v] = 1;
        for(auto &v : nums2) b[v] = 1;
        long da = 0, db = 0;
        int pv = 0;
        for(int i = 0, j = 0; i < nums1.size() || j < nums2.size();){
            int al = (i < nums1.size()) ? nums1[i]: 1e7;
            int bl = (j < nums2.size()) ? nums2[j]: 1e7;
            if(al < bl) i++;
            else if(bl < al) j++;
            else i++, j++;
            int v = min(al, bl);
            if(v == pv) continue;
            if(a[v]) da += v;
            if(b[v]) db += v;
            if(a[v] && b[v]){
                da = max(da, db);
                db = da;
            }
            pv = v;
        }
        return max(da, db) % mod;
    }
};

// O(M+N). Space O(1)
// Autaully, no need to use array to record.
// Can Simple use which is small. then add.
// When same, add the prefix, and go to 0
// Just two pointer and like a game.
// remember finally add a and b because maybe some remain

class Solution {
public:
    const int mod = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long res = 0, a = 0, b = 0;
        int n = nums1.size(), m = nums2.size();
        for(int i = 0, j = 0; i < n || j < m;){
            if(i < n && (j == m || nums1[i] < nums2[j])){
                a += nums1[i++];
            }
            else if(j < m && (i == n || nums2[j] < nums1[i])){
                b += nums2[j++];
            }
            else{
                res += max(a, b) + nums1[i];
                i++, j++;
                a = 0, b = 0;
            }
        }
        return (res + max(a, b)) % mod;
    }
};
