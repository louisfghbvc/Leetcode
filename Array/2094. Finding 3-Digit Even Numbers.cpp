// Solution1 Brute force
// O(N^3)

// Solution 2, enumerate the numbers check if digit occur is enough
// O(N)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for(int x: digits) cnt[x]++;
        
        vector<int> res;
        // enumerate all possible
        for(int i = 100; i < 1000; i += 2){
            int tmp = i;
            int cur[10] = {};
            while(tmp){
                cur[tmp%10]++;
                tmp /= 10;
            }
            bool ok = 1;
            for(int d = 0; d < 10; ++d){
                if(cur[d] > cnt[d]) ok = 0;
            }
            if(ok) res.push_back(i);
        }
        return res;
    }
};
