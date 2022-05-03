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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        ListNode* fast=head;
        ListNode* slow=head;
        int count=0;
        while(fast->next!=NULL and fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            count+=2;
        }
        
        
        
        if(fast->next!=NULL){
            slow=slow->next;
            count+=1;
        }
        
        int target=n-count;
        target--;
        
        while(target--){
            slow=slow->next;
        }
        
        ListNode* temp=slow->next;
        
        
        slow=slow->next->next;
        delete(temp);
        
        return head;
        */
        
        ListNode* slow=head;
        int count=0;
        while(slow!=NULL){
            slow=slow->next;
            count++;
        }
        
        int target=count-n;
        
        ListNode* t1=head;
        ListNode* t2;
        
        if(target>=1){
        target--;
        while(target--){
            t1=t1->next;
        }
        t2=t1->next;

        t1->next=t1->next->next;
        delete(t2);
        }
        else{
            head=head->next;
            delete(t1);
        }
        
        return head;
        
        
    }
};