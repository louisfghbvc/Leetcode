//32ms 11.4MB
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0, n = customers.size(), mx = 0, tmp = 0, l = 0;
        for(int r = 0; r < n; ++r){
            if(!grumpy[r]) 
                sum += customers[r];
            else
                tmp += customers[r];
            if(r - l + 1 > X && grumpy[l++]){
                tmp -= customers[l-1];
            }
            mx = max(mx, tmp);
        }
        
        return sum + mx;
    }
};
