class BIT{
public:
    BIT(int _m=0, int _n=0) : m(_m+1), n(_n+1) {
        data = vector<vector<int>>(m+1, vector<int>(n+1));
    }   
    void update(int row, int col, int diff) {
        for(int i = row+1; i <= m; i+=i&-i)
            for(int j = col+1; j <= n; j+=j&-j)
                data[i][j] += diff;
    }
    int get(int row, int col){
        int res = 0;
        for(int i = row+1; i; i-=i&-i)
            for(int j = col+1; j; j-=j&-j)
                res += data[i][j];
        return res;
    }
private:
    vector<vector<int>> data;
    int m, n;
};


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        ord = matrix; // origin data
        bit = BIT(m, n);
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                bit.update(i, j, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        int diff = val - ord[row][col];
        bit.update(row, col, diff);
        ord[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return bit.get(row2, col2) - bit.get(row2, col1-1) - bit.get(row1-1, col2) + bit.get(row1-1, col1-1);
    }
private:
    vector<vector<int>> ord;
    BIT bit;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
