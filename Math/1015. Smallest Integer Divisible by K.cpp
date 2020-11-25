// O(N). Space O(N). use set.
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int len = 1, re = 1;
        unordered_set<int> st;
        while(re % K){
            if(st.count(re%K)) return -1;
            st.insert(re%K);
            len++;
            re%=K;
            re = re*10 + 1;
        }
        return len;
    }
};

// use array. same.
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int len = 1, re = 1;
        vector<bool> vis(K);
        while(re % K){
            if(vis[re%K]) return -1;
            vis[re%K] = 1;
            len++;
            re%=K;
            re = re*10 + 1;
        }
        return len;
    }
};

// O(N). O(1). if have cycle, means loop all K.
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int len = 1, re = 1;
        for(int i = K; i >= 0; --i, len++){
            if(re%K == 0) return len;
            re%=K;
            re = re*10 + 1;
        }
        return -1;
    }
};
