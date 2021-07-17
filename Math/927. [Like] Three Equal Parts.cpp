// Three Pointers. and math.
// So just count the 1.
// and observe that 1 must be divisible by 3.

class Solution {
public:
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int one = 0;
        for(int i = 0; i < n; ++i){
            one += arr[i] == 1;
        }
        
        if(!one) return {0, n-1};
        if(one % 3) return {-1, -1};
        
        int sz = one / 3;
        int i = 0, j = 0, k = 0; // 1, 2, 3 pointer
        for(int c = 0; c < sz; ++j){
            c += arr[j] == 1;
        }
        for(int c = 0; c < 2*sz; ++k){
            c += arr[k] == 1;
        }
        
        // leading zero
        while(!arr[i]) i++;
        while(!arr[j]) j++;
        while(!arr[k]) k++;
        
        // compare
        for(; k < n; ++i, ++j, ++k){
            if(arr[i] != arr[j] || arr[j] != arr[k]) return {-1, -1};
        }
        
        return {i-1, j};
    }
};
