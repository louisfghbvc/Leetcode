// O(log(N)). m+1 is the num not missing
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size(), m;
        while(l < r){
            m = (l+r)/2;
            if(arr[m] - (m+1) >= k) r = m;
            else l = m+1;
        }
        // cout << l << " " <<r << endl;
        return l+k;
    }
};

// BF. Staight.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        for(int i = 1; ; ++i){
            auto p = lower_bound(arr.begin(), arr.end(), i);
            if(p == arr.end()) cnt++;
            else if(*p != i) cnt++;
            if(cnt == k) return i;
        }
        return -1;
    }
};
