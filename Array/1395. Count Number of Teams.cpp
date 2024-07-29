class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    if(rating[i] < rating[j] && rating[j] < rating[k])
                        ans++;
                    else if(rating[i] > rating[j] && rating[j] > rating[k])
                        ans++;
                }
            }
        }
        return ans;
    }
};



// optimal solution: BIT
class Solution {
public:
    struct BIT {
        vector<int> arr;
        int N;
        BIT (int n) : N(n+1), arr(n+1) {}
        void add(int x, int v=1) {
            for (++x; x < N; x += x&-x)
                arr[x] += v;
        }
        int sum(int x) {
            int res = 0;
            for (++x; x; x -= x&-x) 
                res += arr[x];
            return res;
        }
    };

    int numTeams(vector<int>& rating) {
        // goal: given unique array find out the number of distinct tuple
        // such that ai < aj < ak or ai > aj > ak
        // idea:
        // we can sort array? no, order is need
        // 2 5 3 4 1
        // think the brute force -> O(n^3)
        // enumerate middle
        // x x x x 5 y y y y , x<5, y<5
        // we can use binary tree to compute the number of smaller
        // a better brute force is just count the left and right

        int n = rating.size();

        auto tmp = rating;
        sort(tmp.begin(), tmp.end());
        auto conv = [&](int x) {
            return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
        };

        auto helper = [&]() {
            BIT left(n), right(n);
            for (int i = 0; i < n; ++i)
                right.add(i, 1);

            left.add(conv(rating[0]));
            right.add(conv(rating[0]),-1);

            int res = 0;
            for (int i = 1; i+1 < n; ++i) {
                int id = conv(rating[i]);

                right.add(id, -1);
                int l = left.sum(id);
                int r = n-i-1 - right.sum(id);
                res += l * r;
                left.add(id);
            }
            return res;
        };

        int res = helper();
        reverse(rating.begin(), rating.end());
        res += helper();
        return res;
    }
};
