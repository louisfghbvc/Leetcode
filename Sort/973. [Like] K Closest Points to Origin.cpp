// quick select. avg. O(N)

class Solution {
public:
    // p1 <= p2
    bool com(vector<int> &p1, vector<int> &p2){
        return p1[0]*p1[0] + p1[1]*p1[1] <= p2[0]*p2[0] + p2[1]*p2[1];
    }
    // return index of array smaller than pivot.
    int quickSelect(vector<vector<int>> &arr, int l, int r){
        vector<int> pivot = arr[r];
        int i = l;
        for(int j = l; j < r; ++j){
            if(com(arr[j], pivot)){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[r], arr[i]);
        return i;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size()-1;
        while(l <= r){
            int mid = quickSelect(points, l, r);
            if(mid+1 == k) break;
            else if(mid+1 < k) l = mid+1;
            else r = mid-1;
        }
        points.resize(k);
        return points;
    }
};
