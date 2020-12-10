// O(N). Optimal pass just climb mountain.
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(i+1 < n && arr[i] < arr[i+1]) i++;
        while(j > 0 && arr[j] < arr[j-1]) j--;
        return i > 0 && i == j && j < n-1;
    }
};

// Dummy. down mountain
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        
        int mxi = max_element(arr.begin(), arr.end()) - arr.begin();
        bool up = false, down = false;
        for(int i = mxi; i >= 1; --i){
            if(arr[i-1] >= arr[i]) return false;
            up = true;
        }
        
        for(int i = mxi; i+1 < n; ++i){
            if(arr[i] <= arr[i+1]) return false;
            down = true;
        }
        
        return up & down;
    }
};
