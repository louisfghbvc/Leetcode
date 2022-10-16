class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // goal: compute the subarray max(arr)=maxK, min(arr)=minK
        // idea: sliding window
        
        // minK = 1, maxK = 5
        // bad: nums[i] < minK || nums[i] > maxK
        //.   i
        //  xxxxxxxxxxx
        //.   b  
        //.m
        //.M
        //    p
        
        // ending in i, how many subarray 
        //.                 i
        //   [1,5,7,2,5,3,1,2]
        //
        // m=6
        // M=4
        // p=2
        // ans=1+(4-2)+(4-2)
        
        long ans = 0;
        int n = nums.size();
        int minP = -1, maxP = -1;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) { // bad
                minP = -1, maxP = -1;
                last = i+1;
            }
            if (nums[i] == minK) minP = i;
            if (nums[i] == maxK) maxP = i;
            ans += max(min(minP, maxP) - last + 1, 0);
        }
        
        return ans;
    }
};


// O(N), counting subarray
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // goal: find the number of subarrays such that satisfied the min(arr) = minK, max(arr) = maxK
        
        // idea2: 
        // [1,3,5,2, xx7,5]
        //.     ^     ^
        //.6 xxxx 1x 0 (xxx) 5 (xxxxx 1 xxxx) 7
        
        // 1 1 1 1
        //  
        
        // all possible - no minK pairs
        // for each number -> try to find the closest one minK
        
        
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n); // the closest index minK
        vector<int> prevS(n), nextS(n); // the closest index minK
        {
            int pos = -1;
            int pos2 = -1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == minK)
                    pos = i;
                if (nums[i] < minK)
                    pos2 = i;
                leftMin[i] = pos;
                prevS[i] = pos2;
            }
        }
        {
            int pos = n;
            int pos2 = n;
            for (int i = n-1; i >= 0; --i) {
                if (nums[i] == minK)
                    pos = i;
                if (nums[i] < minK)
                    pos2 = i;
                rightMin[i] = pos;
                nextS[i] = pos2;
            }
        }
        
        vector<int> nextG(n, n), prevG(n, -1); // next greater, prev greater
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() && nums[st.top()] < nums[i]) {
                nextG[st.top()] = i; st.pop();
            }
            if (st.size())
                prevG[i] = st.top();
            st.push(i);
        }
        
        // compute the ans
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxK) {
                int boundL = max(prevG[i], prevS[i]);
                int boundR = min(nextG[i], nextS[i]);
                int left = i-boundL;
                int right = boundR-i;
                long tot = (long)left*right;
                
                int left2 = i-max(leftMin[i], boundL);
                int right2 = min(boundR, rightMin[i])-i;
                
                long sub = (long)left2*right2;
                // cout << boundL << " " << i << " " << boundR << " " << tot << " " << sub << "\n";
                ans += max(tot-sub, 0L);
            }
        }
        
        return ans;
    }
};
