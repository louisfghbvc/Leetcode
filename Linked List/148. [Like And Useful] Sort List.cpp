// Merge sort. top-down. 
// O(NlogN). Space O(logN).

class Solution {
public:
    ListNode* merge(ListNode* l, ListNode* r){
        if(l == NULL) return r;
        if(r == NULL) return l;
        if(l->val > r->val){
            r->next = merge(l, r->next);
            return r;
        }
        l->next = merge(l->next, r);
        return l; 
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *slow, *fast;
        slow = head; fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head); 
        ListNode* right = sortList(fast);
        return merge(left, right);
    }
};


// O(NlogN). O(1). Bottom-up.
// Code is long, but not so hard to understand.
// So from 1, 2, 4, 8....
class Solution {
public:
   ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
		ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur = cur->next = l2;
				l2 = l2->next;
			}
			else{
				cur = cur->next = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
	}
    
    ListNode* split(ListNode* head, int n){
        for(int i = 1; head && i < n; ++i) head = head->next;
        if(!head) return NULL;
        ListNode* second = head->next;
        head->next = NULL;
        return second;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = head;
		int n = 0;
		while(cur) n++, cur = cur->next;
        
        ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
        for(int s = 1; s < n; s *= 2){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, s);
                cur = split(right, s);
                tail = merge(left, right, tail);
            }
        }
        
        return dummy.next;
    }
};
