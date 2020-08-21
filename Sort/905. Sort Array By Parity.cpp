// O(N). Swap. Because no need to sort even so just move even to begin
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int j = 0, i = 0; j < A.size(); ++j){
            if(A[j] % 2 == 0) swap(A[i++], A[j]);
        }
        return A;
    }
};

// O(NlogN). quicksort.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), [&](int a, int b){
            return a%2 < b%2;
        });
        return A;
    }
};
