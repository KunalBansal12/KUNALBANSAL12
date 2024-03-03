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
        int i=1;
        ListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            ++i;
        }
        if(n>i || n==0 || head==NULL){
            return head;
        }
        if(n==i){
            head=head->next;
            return head;
        }
        ListNode *temp1=head;
        for(int j=0;j<i-n-1;j++){
            temp1=temp1->next;
        }
        ListNode *temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next=NULL;
        return head;
    }
};