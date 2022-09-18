// order is no need, observe the negative should always be used

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        // goal: find the minimum money that can do any order transactions
        
        // idea: cost > cashback, always must be add, must need this money
        
        long must_add = 0;
        for (auto &t: transactions) {
            if (t[0] > t[1]) {
                must_add += t[0] - t[1];
            }
        }
        
        long ans = 0;
        for (auto &t: transactions) {
            if (t[0] > t[1]) {
                must_add -= t[0] - t[1];
            }
            ans = max(ans, t[0] + must_add);
            if (t[0] > t[1]) {
                must_add += t[0] - t[1];
            }
        }
        
        return ans;
    }
};

// Binary Search + Greedy
class Solution {
public:
    
    bool sign(vector<int> &v) {
        return v[1]-v[0] >= 0;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        // goal: find the minimumMoney that can finish the transactions in any order
        // idea: binary search, guess the money
        
        // determine the order?
        // sort it by largest cost, minimum cashback -> fail
        
        // sort it base on neg cashback
        // sort it by smallest cashback and greater cost
        
        
        sort(transactions.begin(), transactions.end(), [&](auto &a, auto &b) {
            if (sign(a) != sign(b)) return sign(a) < sign(b);
            return a[1] < b[1];
        }); 
        
        
        int n = transactions.size();
        vector<int> max_right(n);
        long sum = 0;
        sum = max_right.back() = transactions.back()[0];
        for (int i = n-2; i >= 0; --i) {
            max_right[i] = max(max_right[i+1], transactions[i][0]);
            sum += transactions[i][0];
        }
        
        auto good = [&](long x) {
            for (int i = 0; i < n; ++i)  {
                int f = transactions[i][0];
                int s = transactions[i][1];
                if (x >= max_right[i]) {
                    x -= f;
                    x += s;
                }
                else return false;
            }   
            return true;
        };
        
        // O(logMX * N)
        
        long l = 0, r = sum;
        long ans = sum;
        while (l <= r) {
            long mid = (l+r)/2;
            if (good(mid))
                r = mid-1, ans = mid;
            else
                l = mid+1;
        }
        
        return ans;
    }
};
