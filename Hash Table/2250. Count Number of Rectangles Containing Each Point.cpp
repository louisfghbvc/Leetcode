// see the constraints
// O(h(n+q))

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // goal: calculate the number of rectangles that cover points
        // idea: 
        // hash the rectangles y, sort them
        
        int n = rectangles.size();
        vector<vector<int>> height(101);
        for (auto &rect: rectangles) {
            height[rect[1]].push_back(rect[0]);
        }
        
        for (int y = 0; y <= 100; ++y)
            sort(height[y].begin(), height[y].end());
                
        vector<int> res;
        for (auto &p: points) {
            int x = p[0], y = p[1];
            int val = 0;
            for (int k = y; k <= 100; ++k) {
                if (height[k].size()) {
                    int num = lower_bound(height[k].begin(), height[k].end(), x) - height[k].begin();
                    val += height[k].size() - num;
                }
            }
            res.push_back(val);
        }
        
        return res;
    }
};


// prefix sum
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // goal: calculate the number of rectangles that cover points
        // idea: 
        // sort the rectangles
        // for each point, try to binary search the length
        // since the y is small
        // use prefix sum to store y
        
        sort(rectangles.begin(), rectangles.end());
        
        int n = rectangles.size();
        vector<vector<int>> pre(101, vector<int>(n+1));
        
        
        for (int y = 1; y <= 100; ++y) {
            for (int i = 0; i < n; ++i) {
                pre[y][i+1] = pre[y][i] + (rectangles[i][1] == y);
            }
        }
        
        vector<int> res;
        for (auto &p: points) {
            int x = p[0], y = p[1];
            int i = lower_bound(rectangles.begin(), rectangles.end(), p) - rectangles.begin();
            int val = 0;
            for (int k = y; k <= 100; ++k)
                val += pre[k][n] - pre[k][i];
            res.push_back(val);
        }
        
        return res;
    }
};
