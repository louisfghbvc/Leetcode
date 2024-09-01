// Sort by total time

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        // goal: find out the minimum cost we can make all health to zero
        // idea:
        // greedy
        // each time we will choose the maximum damage
        
        // health is no care -> each monster will have same health time
        // a + b
        // a
        
        // WA!!
        
        for (auto &x: health)
            x = (x + power - 1) / power;
        
        vector<pair<long, long>> arr;
        for (int i = 0; i < health.size(); ++i)
            arr.emplace_back(damage[i], health[i]);
        sort(arr.begin(), arr.end(), [&](auto& a, auto &b) {
            long time = a.second + b.second;
            // kill a
            return b.first*time + a.first*a.second < a.first*time + b.first*b.second;
        });
        
        long sum = accumulate(damage.begin(), damage.end(), 0LL);
        long res = 0;
        for (auto &[d, x]: arr) {
            res += sum * x;
            sum -= d;
        }
        
        // 80 79 [2, 1]
        // 79 80
        // 79 80
        // 79 
        // or 
        
        return res;
    }
};
