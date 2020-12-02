// O(N). O(1) space. intuitive.
// just get length first and rand.
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* root;
    int len;
    Solution(ListNode* head) {
        root = head;
        for(len = 0; head; len++, head = head->next);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int x = rand() % len;
        ListNode* cur = root;
        for(int i = 0; i < x; ++i, cur = cur->next);
        return cur->val;
    }
};

// O(1). O(N) space.
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> arr;
    Solution(ListNode* head) {
        for(; head; head = head->next) arr.push_back(head->val);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int x = rand() % arr.size();
        return arr[x];
    }
};

// Reservoir Sampling
// k/l * (l/l+1) * ... * ((n-1)/n) = k/n.
// here k = 1.
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = root;
        int x = 0, l = 0;
        while(cur){
            ++l;
            if(rand() % l == 0) x = cur->val;
            cur = cur->next;
        }
        return x;
    }
};
