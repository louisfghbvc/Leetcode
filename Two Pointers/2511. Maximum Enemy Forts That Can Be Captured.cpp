class Solution {
public:
    int captureForts(vector<int>& forts) {
        // idea: two pointer
        // calculate the maximum continous 0
        // 1 to negative -1
        
        int n = forts.size();
        int ans = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            if (forts[j] == 0) {
                while (j < n && forts[j] == 0) j++;
                int len = j-i;
                if (j < n && i-1 >= 0 && forts[j]+forts[i-1] == 0)
                    ans = max(ans, len);
            }
            else {
                j++;
            }
        }
        
        return ans;
    }
};
