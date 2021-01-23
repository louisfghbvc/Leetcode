//36ms 10.5MB
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int k = 0; k < m; ++k){
            for(int i = 0; i + 1< m; ++i){
                for(int j = 0; j + 1< n; ++j){
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);
                }
            }
        }
        return mat;
    }
};


// O(NMlogD). simple just sort.
class Solution {
public:
    /**
    [3,3,1,1] 00 01 02 03
    [2,2,1,2] 10 11 12 13
    [1,1,1,2] 20 21 22 23
    
    [1,1,1,1]
    [1,2,2,2]
    [1,2,3,3]
    **/
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> arr;
        for(int i = 0; i < m; ++i){
            vector<int> tmp;
            for(int nx = i, ny = 0; nx < m && ny < n; ++nx, ++ny) 
                tmp.push_back(mat[nx][ny]);
            arr.push_back(tmp);
        }
        for(int j = 1; j < n; ++j){
            vector<int> tmp;
            for(int nx = 0, ny = j; nx < m && ny < n; ++nx, ++ny) 
                tmp.push_back(mat[nx][ny]);
            arr.push_back(tmp);
        }
        for(auto&r: arr)
            sort(r.begin(), r.end());
        
        for(int i = 0; i < m; ++i){
            for(int nx = i, ny = 0, k = 0; nx < m && ny < n; ++nx, ++ny, ++k) 
                mat[nx][ny] = arr[i][k];
        }
        for(int j = 1; j < n; ++j){
            for(int nx = 0, ny = j, k = 0; nx < m && ny < n; ++nx, ++ny, ++k) 
                mat[nx][ny] = arr[m+j-1][k];
        }
        
        return mat;
    }
};

// use key i-j, tricky. O(NMlogD). priority queue.

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> arr;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                arr[i-j].push(mat[i][j]);
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                mat[i][j] = arr[i-j].top();
                arr[i-j].pop();
            }
        }
        
        return mat;
    }
};
