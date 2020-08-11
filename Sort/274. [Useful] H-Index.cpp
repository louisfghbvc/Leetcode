// O(N). bucket sort
// so accumulate sum.
// n-h must be in case so only check sum.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> cnt(n+1);
        for(auto &c: citations){
            cnt[min(c, n)]++;
        }
        int sum = 0;
        for(int i = n; i > 0; --i){
            sum += cnt[i];
            if(sum >= i) return i;
        }
        return 0;
    }
};

// O(NlogN). straight.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i = 1; i <= n; ++i){
            if(citations[i-1] >= i && (i == n || citations[i] <= i) )
                return i;
        }
        return 0;
    }
};
