// UF, use find factor, use factor to union.
// use factor mapping to union the index.
// after each group must be small to big. go through origin array.
// put smallest into array.

// T: O(N * sqrt(X) + NlogN)

class Solution {
public:
    
    vector<int> p;
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]); 
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        p.resize(n + 1, -1);
        
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> lastSeen(mx + 1, -1); // factor -> index

        for(int i = 0; i < n; ++i){
            int x = nums[i];
            for(int p = 2; p * p <= x; p++){
                while(x % p == 0){
                    x /= p;
                    if(lastSeen[p] != -1)
                        uni(lastSeen[p], i);
                    lastSeen[p] = i;
                }
            }
            if(x > 1){
                if(lastSeen[x] != -1)
                    uni(lastSeen[x], i);
                lastSeen[x] = i;
            }
        }
        
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> group;
        for(int i = 0; i < n; ++i){
            group[find(i)].push(nums[i]);
        }
        
        vector<int> arr;
        for(int i = 0; i < n; ++i){
            int x = group[find(i)].top(); group[find(i)].pop();
            arr.push_back(x);
        }
        
        for(int i = 1; i < n; ++i){
            if(arr[i-1] > arr[i]) return false;
        }
        
        return true;
    }
};
