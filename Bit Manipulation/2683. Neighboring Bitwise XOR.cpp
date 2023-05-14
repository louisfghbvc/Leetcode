class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // goal: check if existed the original array
        // idea:
        
        // len = 3
        // derived[i] = arr[i] ^ arr[i+1]
        // derived[i+1] = arr[i+1] ^ arr[i+2]
        // derived[i+2] = arr[i+2] ^ arr[i]
        // 
        
        int ans = 0;
        for (int x: derived)
            ans ^= x;
        return ans == 0;
    }
};
