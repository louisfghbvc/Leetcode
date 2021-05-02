// O(N^2). just simulate.

class Solution {
public:
    
    int getMinSwaps(string num, int k) {
        string ord = num;
        for(int i = 0; i < k; ++i){
            next_permutation(num.begin(), num.end());
            // cout << num << endl;
        }
        int swaps = 0;
        for(int i = 0; i < num.size(); ++i){
            int j = i;
            while(num[i] != ord[j]) j++;
            while(i < j){
                swap(ord[j], ord[j-1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};
