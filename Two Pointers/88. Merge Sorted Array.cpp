// O(M+N). So put reverse. so that can be good no replace. if from begin to end, may replace.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, puti = n+m-1;
        while(i >= 0 || j >= 0){
            if(j == -1) nums1[puti--] = nums1[i--];
            else if(i == -1) nums1[puti--] = nums2[j--];
            else nums1[puti--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};
