// Just O(N). Calculate
class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = salary[0], mn = salary[0], mx = salary[0];
        for(int i = 1; i < n; ++i){
            mn = min(mn, salary[i]);
            mx = max(mx, salary[i]);
            sum += salary[i];
        }
        return (double)(sum-mn-mx)/(n-2);
    }
};
