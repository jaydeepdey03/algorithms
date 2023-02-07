// 203. Remove Linked List Elements

// Iterative Method


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp->next!=NULL){
            ListNode* prev = temp;
            if(temp->next->val == val){
                prev = temp->next;
                temp->next = temp->next->next;
                delete prev;
            }else{
            temp = temp->next;
            }
        }
        return dummy->next;
    }
};