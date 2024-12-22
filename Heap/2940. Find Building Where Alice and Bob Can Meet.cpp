class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // goal: find out the meet position of each query
        // jump => i->j, hi<hj
        // position is leftmost

        // idea1:
        // single query
        // 6,4,8,5,2,7
        // ^ ^ 
        // for each index build the right position? 
        // build the next greater value? not enough
        // find out both ai, bi greater
        // offline query.
        // sort the query by largest index of (x,y)
        // a d b c e 
        // from left to right
        // check query is already good
        // else push into a min heap => values
        // looks solution, mess up implement

        int n = heights.size();
        int m = queries.size();

        // sorted queries
        vector<vector<vector<int>>> idx(n);
        // deal with jump ai or bi
        vector<int> ans(m, -1);
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            // 1,2 => right jump to ai or bi
            if (a < b && heights[a] < heights[b]) {
                ans[i] = b;
            }
            else if (a > b && heights[a] > heights[b]) { 
                ans[i] = a;
            }
            else if (a == b) { // same index
                ans[i] = a;
            }
            else {
                idx[max(a,b)].push_back({max(heights[a],heights[b]), i});
            }
        }

        using T = vector<int>;
        priority_queue<T,vector<T>,greater<>> minHeap; // val, index
        for (int i = 0; i < n; ++i) {
            while (minHeap.size() && minHeap.top()[0] < heights[i]) {
                ans[minHeap.top()[1]] = i; minHeap.pop();
            }
            for (auto &v: idx[i])
                minHeap.emplace(v);
        }

        return ans;
    }
};

// idea2: segment tree
class Solution {
public:

    void build(int id, int l, int r) {
        if (l == r) {
            tre[id] = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(id*2+1, l, m);
        build(id*2+2, m+1, r);
        tre[id] = max(tre[id*2+1], tre[id*2+2]);
    }

    int query(int id, int l, int r, int ll, int rr) {
        if (r < ll || rr < l) return 0;
        if (ll <= l && r <= rr) return tre[id];
        int m = (l+r)/2;
        return max(query(id*2+1, l, m, ll, rr), query(id*2+2, m+1, r, ll, rr));
    }

    int getLeft(int pos, int h) {
        int l = pos+1, r = n-1;
        int ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (query(0,0,n-1,pos+1,m) > h)
                ans = m, r = m-1;
            else
                l = m+1;
        }
        return ans;
    };

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // goal: find the left most which is greater
        // idea: 
        // record maximum 
        // [6,4,8,[5,2,7]
        //      ^  5 5 7 -> binary search the index
        // height[r] >= height[l], no need to calculate
        // height[l] > height[r], 
        // if we can know range maximum -> binary search the index

        n = heights.size();
        arr = heights;
        tre.resize(4*n);
        build(0, 0, n-1);

        vector<int> ans;
        for (auto &query: queries) {
            int l = min(query[0], query[1]);
            int r = max(query[0], query[1]);
            if (l == r) 
                ans.push_back(l);
            else if (heights[r] > heights[l]) 
                ans.push_back(r);
            else  // binary search
                ans.push_back(getLeft(r, max(heights[l], heights[r])));            
        }
        return ans;
    }

private:
    vector<int> tre, arr;
    int n;
};
