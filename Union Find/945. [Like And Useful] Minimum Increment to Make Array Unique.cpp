// Tricky. Like sort first, but just like if 2 duplicate become 3. but if already 3. 2 become 4.
// and same cost if 3 => 4. 2 => 3 same as 2=>4, 3=>3
// O(N). Need Space A value.

class Solution {
public:

    unordered_map<int, int> p;
    int find(int x) {
        return p[x] = !p.count(x) ? x : find(p[x]+1);
    }

    int minIncrementForUnique(vector<int>& nums) {
        // goal: find the minimum increment to make element unique
        // idea:
        // starting from smallest to largest
        // 1,1,1,2, 1->2 => 1,[2,2,2]
        // using the couting sort
        // we only have n values
        // idea2:
        // using union find
        // basicly, we need to find the next empty
        // if each value only have one seat, if has allocate just point to next

        int ans = 0;
        for (int x: nums) {
            ans += find(x) - x;
        }
        return ans;
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
