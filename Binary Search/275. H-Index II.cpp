// Very hard to understand this question.
// Just boring. BS, and convert index to true index.
// ex: [0,1,3,5,6]
//      0 1 2 3 4 --> org index
//      5 4 3 2 1 --> true index.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, len = citations.size(), r = len-1;
        while(l <= r){
            int mid = (l+r)/2;
            if((len-mid) <= citations[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return citations.size()-l;
    }
};
