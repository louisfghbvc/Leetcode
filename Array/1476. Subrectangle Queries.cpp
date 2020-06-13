// Just a Design Brute Force Problem
// O(NM).

class SubrectangleQueries {
public:
    int r, c;
    vector<vector<int>> res;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        r = rectangle.size();
        c = rectangle[0].size();
        res = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; ++i)
            for(int j = col1; j <= col2; ++j)
                res[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return res[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
