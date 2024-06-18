class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // goal: find the maximumu profit we can get by assign the job
        // the job can be choose mulitple time
        // idea:
        // sort the worker, order is no matter
        // sort the job by difficulty,
        // start from smallest worker, 
        // using two pointers when a job can be complete <= worker[i], record the maximum profit

        int n = profit.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i)
            arr.push_back({difficulty[i], profit[i]});
        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());

        int ans = 0;
        int j = 0;
        int mx_profit = 0;
        for (int x: worker) {
            while (j < n && arr[j].first <= x) {
                mx_profit = max(mx_profit, arr[j].second);
                j++;
            }
            ans += mx_profit;
        }

        return ans;
    }
};
