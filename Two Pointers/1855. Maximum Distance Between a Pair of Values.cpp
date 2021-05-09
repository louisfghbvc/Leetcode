// O(N). Optimal solution.
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int res = 0;
        for(int j = 0, i = 0; j < m; ++j){
            while(i <= j && i < n && nums1[i] > nums2[j]) i++;
            if(i < n)   
                res = max(j - i, res);
        }
        
        return res;
    }
};


// O(N).
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        queue<int> q;
        int res = 0;
        for(int j = 0, i = 0; j < m; ++j){
            if(i <= j && i < n) q.push(i++);
            while(q.size() && nums1[q.front()] > nums2[j]) q.pop();
            if(q.size()) {
                
                res = max(j - q.front(), res);
            }
                
        }
        
        return res;
    }
};
