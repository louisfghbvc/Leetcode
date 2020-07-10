// O(N^2) can do better.
// Concept is same.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* tolevel1(Node* pre, Node* cur, Node* nxt){
        pre->child = NULL;
        pre->next = cur;
        cur->prev = pre;
        while(cur && cur->next){
            cur = cur->next;
        }
        cur->next = nxt;
        if(nxt) nxt->prev = cur;
        return pre;
    }
    Node* flatten(Node* head) {
        Node* tmp = head;
        while(tmp){
            if(tmp->child){
                tmp = tolevel1(tmp, tmp->child, tmp->next);
            }
            tmp = tmp->next;
        }
        return head;
    }
};

// O(N) get last child. recursive. faster
class Solution {
public:
    Node* helper(Node* head){
        if(!head) return NULL;
        Node *s = head;
        Node *last = NULL;
        while(s){
            last = s;
            Node *t = s->next;
            Node *lc = helper(s->child);
            if(lc){
                s->child->prev = s;
                s->next = s->child;
                lc->next = t;
                if(t) t->prev = lc;
                last = lc;
                s->child = NULL;
            }
            s = t;
        }
        return last;
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
};
