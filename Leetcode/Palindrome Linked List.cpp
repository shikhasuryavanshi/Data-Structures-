class Solution {
public:
    ListNode* reversell(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reversell(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
