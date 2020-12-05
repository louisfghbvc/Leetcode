// Classic problem. so leftmost is best position. put it. add padding in begin, end.
// 000 -> 101.
// Uva scarecrow idea.
// O(N).

class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int sz = arr.size();
        arr.insert(arr.begin(), 0);
        arr.push_back(0);
        for(int i = 1; i <= sz; ++i){
            if(arr[i-1] + arr[i] + arr[i+1] == 0) --n, ++i;
        }
        return n <= 0;
    }
};

// O(N). Counting continuous segment. and edge case is begin end +1.
