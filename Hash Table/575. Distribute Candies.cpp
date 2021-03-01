// O(N). Simple.

class Solution {
public:
    // just use set to determine the type
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(int x: candyType)
            st.insert(x);
        return min(st.size(), candyType.size()/2);
    }
};

// O(N). use bitset. more fast.
class Solution {
public:
    // just use set to determine the type
    // use bitset trick.
    int distributeCandies(vector<int>& candyType) {
        bitset<200001> bt;
        for(int x: candyType)
            bt[x+1e5] = 1;
        return min(bt.count(), candyType.size()/2);
    }
};
