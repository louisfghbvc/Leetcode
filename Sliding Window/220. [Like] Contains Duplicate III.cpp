// O(NlogK).
// It's simple to observe can maintain a window size is k.
// So because want to find the diff abs(arr[i]-arr[j]) <=t.
// |arr[i] - arr[j]| <= t, turn to -->      -t <= arr[i]-arr[j] <= t.
// first, current is arr[r]. so arr[j]-t <= arr[i]. (u can change arr[i], arr[j].) doesn't matter.
// so find lower_bound. arr[j]-t(or arr[i]-t here is arr[i]-t)
// then arr[i]-arr[j] <= t. just simple math check self. 

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(!k) return false;
        int n = nums.size();
        multiset<long> st;
        for(int r = 0, l = 0; r < n; ++r){
            if(st.size() > k){
                st.erase(st.find(nums[l++]));
            }
            if(st.size() && st.size() <= k){
                auto p = st.lower_bound((long)nums[r]-t);
                if(p != st.end() && *p-nums[r] <= t) return true;
            }
            st.insert(nums[r]);
        }
        return false;
    }
};

// O(N). use Bucket concept. impressive.
// think about t is 3. 
// so a bucket put 4 number.
// bucket[0] = 0, 1, 2, 3.
// bucket[1] = 4, 5, 6, 7.
// bucket[2] = 8, 9, 10, 11.
// clearly, in a single bucket can find a t. or neighbor bucket.
// care about neg. say -1. should be bucket[-1].
// overflow issue. remember.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(!k || t < 0) return false;
        int n = nums.size();
        unordered_map<int, int> bucket;
        for(int i = 0, l = 0; i < n; ++i){
            if(bucket.size() > k){
                int remove_key = nums[l]/((long)t+1);
                if(nums[l++] < 0) --remove_key;
                bucket.erase(remove_key);
            }
            
            int key = nums[i]/((long)t+1);
            if(nums[i] < 0) key--;
            
            if(bucket.count(key)) return true;
            else{
                bucket[key] = nums[i];
                // bigger value 
                if(bucket.count(key+1) && (long) bucket[key+1] - nums[i] <= t) return true;
                // smaller value
                if(bucket.count(key-1) && (long) nums[i] - bucket[key-1] <= t) return true;
            }
        }
        return false;
    }
};
