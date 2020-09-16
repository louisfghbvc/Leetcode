// Dp O(N).
// So a lemma a ^ b = c, a ^ c = b. cool. just find the max c if exist.
// Slow, but clean
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0;
        for(int i = 31; i >= 0; --i){
            mask |= (1<<i);
            unordered_set<int> st;
            for(int x : nums){
                st.insert(x & mask);
            }
            
            int tmp = res | (1<<i);
            for(int prefix : st){
                if(st.count(prefix ^ tmp)){
                    res = tmp;
                    break;
                }    
            }
        }
        return res;
    }
};

// O(N). Trie. Simple build a trie.
class Solution {
public:
    struct node{
        node *next[2];
        node(){
            memset(next, 0, sizeof next);
        }
    };
    node *root;
    
    void add(int x){
        node* tmp = root;
        for(int i = 31; i >= 0; --i){
            bool bit = x&(1<<i);
            if(!tmp->next[bit])
                tmp->next[bit] = new node();
            tmp = tmp->next[bit];
        }
    }
    
    int search(int x){
        node* tmp = root;
        int res = 0;
        for(int i = 31; i >= 0; --i){
            bool cur = x&(1<<i);
            if(tmp->next[!cur]){
                res |= (1<<i);
                tmp = tmp->next[!cur];
            }
            else
                tmp = tmp->next[cur];
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new node();
        for(int x: nums){
            add(x);
        }
        int mx = 0;
        for(int x: nums){
            mx = max(search(x), mx);
        }
        return mx;
    }
};
