// O(N^2). O(1) space;
// 2pass

class Solution {
public:
    int getId(Node* head, Node* tar){
        int i;
        for(i = 0; ; ++i){
            if(head == tar) return i;
            head = head->next;
        }
        return i;
    }
    
    Node* get(Node* head, int i){
        for(int j = 0; j < i; ++j) head = head->next; 
        return head;
    }
    
    Node* copyRandomList(Node* head) {
        Node* ohead = head;
        Node *dummy = new Node(0);
        Node *cur = dummy;
        while(head){
            cur->next = new Node(head->val);
            head = head->next;
            cur = cur->next;
        }
        
        head = ohead;
        cur = dummy->next;
        while(head){
            if(head->random){
                int i = getId(ohead, head->random);
                cur->random = get(dummy->next, i);
            }
            head = head->next;
            cur = cur->next;  
        }
        return dummy->next;
    }
};


// Concise awesome O(N). O(1).
// self copy... tricky
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head, *next;
        while(cur){
            next = cur->next;
            
            Node* tmp = new Node(cur->val);
            cur->next = tmp;
            tmp->next = next;
            
            cur = next;
        }
        
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        Node* dummy = new Node(0);
        Node* dummy2 = dummy;
        cur = head;
        while(cur){
            next = cur->next->next;
            
            dummy2->next = cur->next;
            dummy2 = dummy2->next;
            
            cur->next = next;
            cur = next;
        }
        
        return dummy->next;
    }
};
