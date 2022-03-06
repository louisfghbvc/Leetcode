// neat code!.
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // sort, remove duplicate
        // minus the existed number, add greater value
        
        long ans = (long)k*(k+1)/2;
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        for(int x: nums){
            if(x <= k){
                ans -= x;
                ans += ++k;
            }    
        }
        
        return ans;
    }
};

// simple, just calculate the gap
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // sort the nums
        // 1, 4, 10, 25, 25
        sort(nums.begin(), nums.end());
        
        int prev = 0;
        long sum = 0;
        for(int x: nums){
            if(prev+1 >= x){
                prev = x;
                continue;
            }
            else{
                int num = x - prev - 1;
                if(k >= num){
                    k -= num;
                    sum += (long)num*(prev+x)/2;
                }
                else{
                    sum += (long)k*(prev+1+prev+k)/2;
                    k = 0;
                    break;
                }
            }
            prev = x;
        }
        if(k)
            sum += (long)k*(prev+1+prev+k)/2;
        
        return sum;
    }
};
