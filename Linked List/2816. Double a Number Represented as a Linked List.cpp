/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* doubleIt(ListNode* head) {
        // goal: double the linkedlist
        // idea: 
        // convert linked list to vector
        // twice it, convert back
        
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        
        reverse(arr.begin(), arr.end());

        // double twice
        vector<int> res(arr.size(), 0);
        res.push_back(0);
        for (int i = 0; i < arr.size(); ++i) {
            int sum = res[i] + arr[i]*2;
            res[i+1] = sum / 10;
            res[i] = sum % 10;
        }
        if (res.back() == 0) res.pop_back();
        arr = res;
        
        reverse(arr.begin(), arr.end());
        
        
        
        ListNode dummy;
        ListNode* cur = &dummy;
        for (int x: arr) {
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return dummy.next;
    }
};
