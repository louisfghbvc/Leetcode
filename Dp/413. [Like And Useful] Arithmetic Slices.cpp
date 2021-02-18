// O(N^3).
class Solution {
public:
    bool valid(vector<int> &arr, int l, int r){
        int d = arr[l+1] - arr[l];
        for(int i = l+1; i <= r; ++i){
            if(arr[i] - arr[i-1] != d) return false;
        }
        return true;
    }
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
	    int res = 0;
	
        for(int i = 0; i < n; ++i){
		    for(int j = i+2; j < n; j++){
			    if(valid(arr, i, j)) res++;
            }
        }
        return res;
    }
    
};

// O(N^2).
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
	    int res = 0;
        for(int i = 0; i+2 < n; ++i){
            int d = arr[i+1] - arr[i];
		    for(int j = i+2; j < n; j++){
                if(arr[j] - arr[j-1] == d) res++;
                else break;
            }
        }
        return res;
    }
    
};

// O(N). dp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
	    int res = 0;
        vector<int> dp(n);
        for(int i = 2; i < n; ++i){
            if(arr[i] - arr[i-1] == arr[i-1] - arr[i-2]){
                dp[i] = dp[i-1]+1;
                res += dp[i];
            }
        }
        return res;
    }
    
};

// O(N). Continuous array trick.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
	    int res = 0, cnt = 0;
        for(int i = 2; i < n; ++i){
            if(arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) cnt++;
            else cnt = 0;
            res += cnt;
        }
        return res;
    }
    
};
