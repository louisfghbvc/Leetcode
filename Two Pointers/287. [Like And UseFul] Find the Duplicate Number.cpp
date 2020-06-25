//O(NlogN) sort + Binary Search

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] < mid+1){
                r = mid - 1;
            }
            else l = mid+1;
        }
        return l;
    }
};

// Solution2 use hash
// O(N).
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x: nums){
            if(st.count(x)) return x;
            st.insert(x);
        }
        return -1;
    }
};

// Solution 3 two pointer. floyd cycle
// make function be f(x) =  nums[x]
// so there is a cycle.
// first jump until meet
// second find start point
// 2*(F+a) = F + nC + a => F+a = nC
// so turtle is 0, after F steps, rabbit is F+a+nC+F => nC+F, nC can be zero

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = nums[0], b = nums[0];
        do{
            a = nums[a];
            b = nums[nums[b]];
        }while(a != b);
        
        a = nums[0];
        while(a != b){
            a = nums[a];
            b = nums[b];
        }
        return a;
    }
};
