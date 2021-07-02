// Hard to understand...
// Lee is too awesome
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-k;
        
        while(l < r){
            int mid = (l+r)/2;
            if(x - arr[mid] > arr[mid + k] - x) l = mid + 1;
            else r = mid;
        }
    
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};


// O(N). Two Pointers.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        
        while(r - l + 1 > k){
            if(abs(arr[l] - x) > abs(arr[r] - x)) l++;
            else r--;
        }
    
        return vector<int>(arr.begin()+l, arr.begin()+r+1);
    }
};


// O(log(N) + k). use dummy.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    
        int l = max(idx - k, 0);
        int r = min(idx + k, n - 1);
        
        while(r - l + 1 > k){
            if(abs(x - arr[r]) >= abs(x - arr[l])) r--;
            else l++;
        }
        
        return vector<int>(arr.begin()+l, arr.begin()+r+1);
    }
};
