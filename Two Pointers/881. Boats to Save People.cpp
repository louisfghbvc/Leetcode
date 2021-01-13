// Dummy multiset. O(NlogN). space O(N).
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        multiset<int> st(people.begin(), people.end());
        while(st.size()){
            int x = *st.rbegin();
            st.erase(st.find(*st.rbegin()));
            if(st.size() && *st.begin() <= limit - x) st.erase(st.begin());
            res++;
        }
        return res;
    }
};

// sort. O(NlogN). and just two pointer. cuz big pair small.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int res = 0;
        for(int l = 0, r = n-1; l <= r; r--){
            if(people[r] + people[l] <= limit){
                l++;
            }
            res++;
        }
        return res;
    }
};

// O(N). Space O(limit).
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> fre(limit+1);
        for(int x: people) fre[x]++;
        
        int res = 0;
        int l = 1, r = limit;
        while(l <= r){
            while(l <= r && fre[l] <= 0) l++;
            while(l <= r && fre[r] <= 0) r--;
            if(fre[l] <= 0 && fre[r] <= 0) break;
            
            if(l+r <= limit) fre[l]--;
            res++;
            fre[r]--;
        }
        
        return res;
    }
};
