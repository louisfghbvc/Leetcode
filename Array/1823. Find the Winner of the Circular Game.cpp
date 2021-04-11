// O(N^2). BF.
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) arr[i] = i+1;
        k--;
        int cur = 0;
        while(arr.size() > 1){
            cur = (cur + k) % arr.size();
            arr.erase(arr.begin() + cur);
        }
        return *arr.begin();
    }
};

// find the pattern. O(N)
// win(n) = (win(n-1) + k) % n
class Solution {
public:
    int findTheWinner(int n, int k) {
        int x = 0;
        for(int i = 1; i <= n; ++i){
            x = (x + k) % i;
        }
        return x+1;
    }
};
