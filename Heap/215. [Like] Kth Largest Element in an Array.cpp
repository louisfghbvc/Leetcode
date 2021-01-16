// O(NlogN). O(1).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

// O(NlogK). O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x: nums){
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};


// O(N). quick select.
class Solution {
public:
    int partition(vector<int>&nums, int l, int r){
        int pivot = nums[r];
        int i = l;
        for(int j = i; j < r; ++j){
            if(nums[j] <= pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        k = nums.size()-k;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int b = partition(nums, l, r);
            if(b == k) break;
            else if(b < k) l = b+1;
            else r = b-1;
        }
        return nums[k];
    }
};
