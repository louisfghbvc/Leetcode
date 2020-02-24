//40ms 11.5MB
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0, n = customers.size(), mx = 0;
        for(int i = 0; i < n; ++i){
            if(!grumpy[i]) 
                sum += customers[i];
        }
        
        int l = 0, tmp = 0;
        for(int r = 0; r < n; ++r){
            if(grumpy[r])
                tmp += customers[r];
            if(r - l + 1 > X && grumpy[l++]){
               tmp -= customers[l-1];
            }
            mx = max(mx, tmp);
        }
        
        return sum + mx;
    }
};
