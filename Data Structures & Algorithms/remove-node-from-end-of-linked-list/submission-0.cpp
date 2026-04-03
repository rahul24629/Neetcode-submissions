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
    int getSize(ListNode* head){
        int size=0;
        ListNode* curr=head;

        while(curr!=nullptr){
            size++;
            curr=curr->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=getSize(head);

        int n2=size-n+1;
        int count=1;
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;

        while(curr!=nullptr){
            if(count==n2){
                ListNode* temp=curr;
                prev->next=curr->next;
                delete temp;
                break;
            }
            prev=curr;
            curr=curr->next;
            count++;
        }

        return dummy->next;
        
    }
};
