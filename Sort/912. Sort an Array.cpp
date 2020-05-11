// Merge Sort. 48ms. 16.3MB. global space.
class Solution {
public:
    vector<int> tmp;
    void merge_sort(vector<int> &nums, int l, int r){
        if(r - l < 1) return;
        int mid = (l+r)/2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);
        int ls = l, rs = mid+1, s = l;
        while(ls <= mid && rs <= r){
            if(nums[ls] < nums[rs])
                tmp[s++] = nums[ls++];
            else
                tmp[s++] = nums[rs++];
        }
        while(ls <= mid) tmp[s++] = nums[ls++];
        while(rs <= r) tmp[s++] = nums[rs++];
        for(int i = l; i < r; ++i)
            nums[i] = tmp[i];
        
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};

// Beautiful code. 440ms. 135MB. but space is big.
class Solution {
public:
    vector<int> merge_sort(vector<int> nums){
        if(nums.size() <= 1) return nums;
        int mid = nums.size()/2;
        vector<int> left = merge_sort(vector<int>(nums.begin(), nums.begin()+mid));
        vector<int> right = merge_sort(vector<int>(nums.begin()+mid, nums.end()));
        vector<int> res;
        int ls = 0, rs = 0;
        while(ls < left.size() && rs < right.size()){
            if(left[ls] < right[rs])
                res.push_back(left[ls++]);
            else
                res.push_back(right[rs++]);
        }
        while(ls < left.size()) res.push_back(left[ls++]);
        while(rs < right.size()) res.push_back(right[rs++]);
        return res;
    }
    vector<int> sortArray(vector<int>& nums) {
        return merge_sort(nums);
    }
};

// STL quick sort 68ms 15.6MB.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
