class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // goal: find the sum of product of a team
        // all team size is 2, and sum is all the same
        // idea:
        // sort skill, and pair them (arr[i], arr[n-1-i])
        // 1 2 3 3 4 5 
        // ^         ^
        //   ^     ^
        //     ^ ^
        
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int sum = skill[0] + skill[n-1];
        
        long ans = 0;
        for (int i = 0; i < n/2; ++i) {
            int cur = skill[i] + skill[n-1-i];
            if (cur != sum) return -1;
            ans += skill[i] * skill[n-1-i];
        }
        
        return ans;
    }
};


// O(n), two sum
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // goal: find out a divide ways such that all team sum is equal
        // find the sum of product of a team

        // idea:
        // think about n is even
        // sum / (n/2)
        // [1,2,3,4] => the sum is fix     
        // we can just using two sum! to find the proper value!

        int n = skill.size();
        long sum = accumulate(skill.begin(), skill.end(), 0LL);
        if (sum % (n/2)) return -1;
        sum /= n/2;

        unordered_map<int, int> idx;
        long ans = 0;
        int cnt = 0;
        for (int x: skill) {
            if (idx[sum-x] > 0) {
                idx[sum-x]--;
                ans += x * (sum-x);
                cnt++; // find a pair
            }
            else {
                idx[x]++;
            }
        }

        return cnt == n/2 ? ans : -1;
    }
};
