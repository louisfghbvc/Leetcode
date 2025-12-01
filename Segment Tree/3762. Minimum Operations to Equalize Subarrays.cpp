class Solution {
public:

    struct Node {
        long cnt, sum;
        Node*l, *r;
        Node(long c=0, long s=0, Node *ll = nullptr, Node *rr = nullptr) : cnt(c), sum(s), l(ll), r(rr) {}
    };
    vector<Node*> versions;

    Node* build(int l, int r) {
        if (l == r) return new Node;
        Node* res = new Node;
        int m = (l+r)/2;
        res->l = build(l, m);
        res->r = build(m+1, r);
        return res;
    }

    Node* update(Node* old, int l, int r, int idx, int val) {
        if (l == r) {
            return new Node(old->cnt+1, old->sum+val); 
        }
        int m = (l+r)/2;
        Node* res = new Node;
        if (idx <= m) {
            res->l = update(old->l, l, m, idx, val);
            res->r = old->r;
        }
        else {
            res->l = old->l;
            res->r = update(old->r, m+1, r, idx, val);
        }
        // merge
        res->cnt = res->l->cnt + res->r->cnt;
        res->sum = res->l->sum + res->r->sum;
        return res;
    }

    long kth(Node* nl, Node* nr, int l, int r, int k) {
        if (l == r) return l;
        // check left tree first
        int cntLeft = nr->l->cnt - nl->l->cnt;
        int m = (l+r)/2;
        if (cntLeft >= k) 
            return kth(nl->l, nr->l, l, m, k);
        return kth(nl->r, nr->r, m+1, r, k-cntLeft);
    }
    
    // [l,r] sum, cnt <= x
    pair<long, long> prefix(Node* nl, Node* nr, int l, int r, int x) {
        if (l > x) return {0, 0};
        if (r <= x) return {nr->sum - nl->sum, nr->cnt - nl->cnt};
        int m = (l+r)/2;
        auto left = prefix(nl->l, nr->l, l, m, x);
        auto right = prefix(nl->r, nr->r, m+1, r, x);
        return {right.first + left.first, right.second + left.second};
    }

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // operation:
        // inc or dec any element by k

        // query:
        // find minimum ops to make [l,r] equal

        // 1. can equal => mod % k all the same
        // 2. ops => in demand compute
        // x,x+k,x+2k,x+3k,x+4k (1+2+3+4)

        // [l,r] can equal => find median value => best value =
        // ops = (nums[i] - mid) / k
        // ops[l,r] = (sum[l,r] - mid*(r-l+1)) / k => wrong

        // (mid*h - left sum + right sum - mid*h) / k

        // 1. check last position of mod value, each query easy to check
        // 2. pst, we could use two segment tree to get one value


        int n = nums.size();

        // step1, check mod
        vector<int> last(n, 0);
        for (int i = 1; i < n; ++i) {
            if (nums[i] % k == nums[i-1] % k) {
                last[i] = last[i-1];
            }
            else {
                last[i] = i;
            }
        }

        // step2, value rerange
        auto tmp = nums;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        auto ID = [&](int x) {
            return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
        };
        
        // step3, pst
        int M = tmp.size();
        versions.resize(n+1);
        versions[0] = build(0, M-1);
        for (int i = 0; i < n; ++i) {
            int id = ID(nums[i]);
            versions[i+1] = update(versions[i], 0, M-1, id, nums[i]);
        }   

        // step4, ans
        vector<long long> ans;
        for (auto &q: queries) {
            int l = q[0], r = q[1];
            int j = last[r];
            if (j <= l) {
                int len = r-l+1;
                int k_th = (len+1)/2;
                int midIdx = kth(versions[l], versions[r+1], 0, M-1, k_th);
                long midVal = tmp[midIdx];
                auto [leftSum, leftCnt] = prefix(versions[l], versions[r+1], 0, M-1, midIdx);
                auto totalSum = versions[r+1]->sum - versions[l]->sum;
                long rightSum = totalSum - leftSum;
                long rightCnt = len - leftCnt;
                ans.push_back((midVal * leftCnt - leftSum + rightSum - midVal * rightCnt) / k);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
