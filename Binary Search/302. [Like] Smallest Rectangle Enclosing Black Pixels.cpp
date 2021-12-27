class Solution {
public:
    
    // search 4 edge
    // left = [0, y]
    // 0 1 1) 0
    // right = [y, n]
    
    bool haveAnyOneCol(int j){
        for(int i = 0; i < image.size(); ++i){
           if(image[i][j] == '1') return true; 
        }
        return false;
    }
    bool haveAnyOneRow(int i){
        for(int j = 0; j < image[0].size(); ++j){
           if(image[i][j] == '1') return true; 
        }
        return false;
    }
    
    int searchCols(int left, int right, bool smaller=true){
        int ans = 0;
        
        while(left <= right){
            int mid = (left + right) / 2;
            // is this col have one?
            if(smaller){
                if(haveAnyOneCol(mid)) ans = mid, right = mid-1;
                else left = mid+1;
            }
            else{
                if(haveAnyOneCol(mid)) ans = mid, left = mid+1;
                else right = mid-1;
            }
        }
        
        return ans;
    }
    
    int searchRows(int left, int right, bool smaller=true){
        int ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            // is this col have one?
            if(smaller){
                if(haveAnyOneRow(mid)) ans = mid, right = mid-1;
                else left = mid+1;
            }
            else{
                if(haveAnyOneRow(mid)) ans = mid, left = mid+1;
                else right = mid-1;
            }
        }
        return ans;
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        this->image = image;
        
        int left = searchCols(0, y);
        int right = searchCols(y, n-1, false);
        int top = searchRows(0, x);
        int bottom = searchRows(x, m-1, false);
        
        return (right - left + 1) * (bottom - top + 1);
    }
private:
    vector<vector<char>> image;
};
