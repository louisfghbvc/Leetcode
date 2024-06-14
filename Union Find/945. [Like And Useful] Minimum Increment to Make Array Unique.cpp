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

// Approach2, sort the array, and compare with previous value
class Solution {
public:

    int minIncrementForUnique(vector<int>& nums) {
        // goal: find the minimum increment to make element unique
        // idea:
        // sort the array, 
        // when arr[i-1] >= arr[i], arr[i] is duplicate, need to change to arr[i-1]+1
        // 2,2,3,3,,5
        // 2 3,3
        //     ^
        // 2 3 4,3
        //       ^
        ranges::sort(nums);
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] >= nums[i]) {
                int newValue = nums[i-1]+1;
                ans += newValue - nums[i];
                nums[i] = newValue;
            }
        }

        return ans;
    }
};

// Approach3, counting sort
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // goal: find the minimum increment to make element unique
        // idea:
        // starting from smallest to largest
        // 1,1,1,2, 1->2 => 1,[2,2,2]
        // using the couting sort
        // we only have n values

        vector<int> cnt(2e5+5);
        int mn = *min_element(nums.begin(), nums.end());
        for (int x: nums)
            cnt[x-mn]++;
        
        int ans = 0;
        for (int i = 0; i <= 2e5; ++i) {
            int move = max(cnt[i]-1, 0);
            cnt[i+1] += move;
            ans += move;
        }
        return ans;
    }
};
