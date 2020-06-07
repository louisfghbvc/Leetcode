// Sort two times.
// First sort small to big
// Second sort by abs(i-m), and arr[i] > arr[j]
// O(NlogN) + O(NlogN)

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
// Second sort can use Two Pointer, Very Fast
// O(NlogN)
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int m = arr[(n-1)/2];
        vector<int> res;
        int i = 0, j = arr.size()-1;
        while(res.size() < k){
            if(abs(arr[i] - m) > abs(arr[j] - m))
                res.push_back(arr[i++]);
            else
                res.push_back(arr[j--]);
        }
        return res;
    }
};

// use quick select algorithm get mid, and maintain queue.
// O(nlogk)
