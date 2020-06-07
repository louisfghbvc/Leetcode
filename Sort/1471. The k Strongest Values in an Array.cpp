// Sort two times.
// First sort small to big
// Second sort by abs(i-m), and arr[i] > arr[j]
// O(NlogN)

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int m = arr[(n-1)/2];
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            return abs(a-m) > abs(b-m) || (abs(a-m)== abs(b-m) && a > b);
        });
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};

// Can be Optimal.
// Second sort can use Two Pointer
