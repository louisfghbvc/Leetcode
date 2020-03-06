/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

//0ms 8.0MB O(X + Y), Impressive Lee
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int y = 1000;
        for(int x = 1; x <= 1000; ++x){
            while(y > 1 && customfunction.f(x, y) > z) y--;
            if(customfunction.f(x, y) == z)
                res.push_back({x, y});
        }

        return res;
    }
};

//4ms 7.7MB, Binary Search 
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for(int x = 1; x <= 1000; ++x){
            int yl = 1, yr = 1000, mid;
            while(yl <= yr){
                mid = (yl + yr) / 2;
                if(customfunction.f(x, mid) == z){
                    res.push_back({x, mid});
                    break;
                }
                else if(customfunction.f(x, mid) > z)
                    yr = mid - 1;
                else
                    yl = mid + 1;
            }
        }

        return res;
    }
};
