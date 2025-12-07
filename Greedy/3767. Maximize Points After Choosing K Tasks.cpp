class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        // k: at least k using t1 points
        // each task could use either t1 or t2
        // maximum points we could get


        // idea:
        // choose max of a1[i] or a2[i]
        // t1[i] < t2[i] => we need to choose t1 since k is > 0
        // sort => t1[i]-t2[i], pick k first

        int n = t1.size();
        vector<int> removeQ;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(t1[i], t2[i]);
            if (t1[i] < t2[i]) {
                removeQ.push_back(t2[i]-t1[i]);
            }
            else { // use t1
                k--;
            }
        }
        ranges::sort(removeQ);
        for (int i = 0; i < min((int)removeQ.size(), k); ++i) {
            ans -= removeQ[i];
        }
        return ans;
    }
};
