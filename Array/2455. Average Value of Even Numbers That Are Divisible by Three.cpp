class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0;
        int cnt = 0;
        for (int x: nums) {
            if (x % 2 == 0 && x % 3 == 0)
                total += x, cnt++;
        }
        return cnt == 0 ? 0 : total / cnt;
    }
};
