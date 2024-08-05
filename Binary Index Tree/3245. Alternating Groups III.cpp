class Solution {
public:
    struct BIT {
        vector<array<int, 2>> arr; 
        int N;
        BIT(int n) : N(n+1), arr(n+1) {}
        // v = 1, add
        // v = -1, erase
        void update(int x, int v) {
            int val = x*v;
            for (++x; x < N; x += x&-x) {
                arr[x][0] += val;
                arr[x][1] += v;
            }
        }
        // return: sum, cnt
        array<int, 2> sum(int x) {
            array<int, 2> res{};
            for (++x; x; x -= x&-x) {
                res[0] += arr[x][0];
                res[1] += arr[x][1];
            }
            return res;
        }
    };

    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        // idea:
        // using endpoint to represent the segment
        // record endpoint into set
        // e.g, i and j is endpoint
        // means c[i]==c[i+1], c[j]==c[j+1]
        // the alternating length = j-i
        // x x x x x
        //   i     j
        
        // for a alternaing group len k
        // is we need find size
        // we have number is k−(size−1)
        // if we have 3 alternaing group
        // k1−(size−1) + k2−(size−1) + ... where ki >= size
        // k1 + k2 + ... - cnt * (size-1)

        int n = colors.size();
        BIT tree(n+1);
        set<int> st; // endpoint

        // remove odd, add new two interval
        auto update = [&](int i, int isAdd) {
            auto it = st.lower_bound(i);
            int pre = it == st.begin() ? *st.rbegin() : *prev(it);
            int nxt = it == st.end() ? *st.begin() : *it;

            int dis = (nxt - pre + n) % n;
            if (dis == 0) dis = n;
            tree.update(dis, -isAdd);

            dis = (i - pre + n) % n;
            if (dis == 0) dis = n;
            tree.update(dis, isAdd);

            dis = (nxt - i + n) % n;
            if (dis == 0) dis = n;
            tree.update(dis, isAdd);
        };

        // add a end point
        auto add = [&](int i) {
            if (st.empty()) { // all are alternating
                tree.update(n, 1);
            }
            else {
                update(i, 1);
            }
            st.insert(i);
        };
        auto remove = [&](int i) {
            st.erase(i);
            if (st.empty()) { // all are alternating
                tree.update(n, -1);
            }
            else {
                update(i, -1);
            }
        };

        for (int i = 0; i < n; ++i) {
            if (colors[i] == colors[(i+1)%n])
                add(i);
        }

        vector<int> res;
        for (auto &q: queries) {
            if (q[0] == 1) { 
                if (st.empty()) {
                    res.push_back(n);
                }
                else {
                    auto [sumR, cntR] = tree.sum(n);
                    auto [sumL, cntL] = tree.sum(q[1]-1);
                    int sum = sumR-sumL, cnt = cntR-cntL;
                    res.push_back(sum - cnt * (q[1] - 1));
                }
            }
            else { // update
                int i = q[1], pre = (i-1+n)%n, nxt = (i+1)%n;
                if (colors[i] == q[2]) continue;
                if (colors[pre] == colors[i])
                    remove(pre);
                if (colors[i] == colors[nxt])
                    remove(i);
                colors[i] ^= 1;
                if (colors[pre] == colors[i])
                    add(pre);
                if (colors[i] == colors[nxt])
                    add(i);
            }
        }

        return res;
    }
};
