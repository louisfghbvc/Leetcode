// O(N). ugly
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a = LLONG_MIN, b = a, c = a;
        for(auto &x: nums){
            if(x > a){
                c = b;
                b = a;
                a = x;
            }
            else if(x < a && x > b){
                c = b;
                b = x;
            }
            else if(x < a && x < b && x > c){
                c = x;
            }
        }
        return c == LLONG_MIN ? a : c;
    }
};


// O(Nlog(3)) == O(N).
// Clean.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(int x: nums){
            st.insert(x);
            if(st.size() > 3) st.erase(st.begin());
        }
        return st.size() < 3 ? *st.rbegin() : *st.begin();
    }
};
