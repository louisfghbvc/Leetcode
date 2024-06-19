// Hard to think. Binary Search. 
// The magic is guess ans, then using two pointers to compute the bouquet
// O(NlogV)

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // bloomDay, m, k
        // make a bouquet need k flowers from the garden
        // each flower will used in exactly one bouquet
        // bloomDay[i]: flower will bloom after this day

        // idea:
        // impossible: k*m > n
        // [1,10,3,10,2], m = 3, k = 2 => impossible
        // binary search the days
        // F(d) -> numbers of bloomdays we can make
        // when given a days, we can use two pointers to calculate the bouquet
        // O(nlogX)
        
        auto good = [&](int day) -> int {
            int res = 0;
            for (int i = 0, j; i < bloomDay.size(); i = j) {
                j = i;
                while (j < bloomDay.size() && bloomDay[j] <= day) j++;
                int len = j-i;
                res += len / k;
                if (j == i) j++; // no flowers on this day
            }
            return res;
        };

        int l = 0, r = 1e9;
        int ans = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (good(mid) >= m) ans = mid, r = mid-1;
            else l = mid+1;
        }

        return ans;
    }
};


