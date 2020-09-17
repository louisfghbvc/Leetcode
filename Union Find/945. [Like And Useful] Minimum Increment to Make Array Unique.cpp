// Tricky. Like sort first, but just like if 2 duplicate become 3. but if already 3. 2 become 4.
// and same cost if 3 => 4. 2 => 3 same as 2=>4, 3=>3
// O(N). Need Space A value.

class Solution {
public:
    int p[80005];
    int find(int x){
        return p[x] = p[x] < 0 ? x : find(p[x]+1);
    }
    int minIncrementForUnique(vector<int>& A) {
        memset(p, -1, sizeof p);
        int res = 0;
        for(int x : A){
            res += find(x) - x;
        }
        return res;
    }
};

// If observe the same cost when (2=>4, 3=>3) (3=>4, 2=>3). just sort.
// and when duplicate change.
// O(NlogN).

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0;
        sort(A.begin(), A.end());
        
        for(int i = 0; i < A.size(); ++i){
            if(i && A[i] <= A[i-1]){
                res += A[i-1]-A[i]+1;
                A[i] = A[i-1]+1;
            }    
        }
        
        return res;
    }
};
