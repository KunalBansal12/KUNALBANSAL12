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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return NULL;
        }
        ListNode *head1=NULL;
        ListNode *temp1=head1;
        ListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            int num=0;
            while(temp!=NULL && temp->val!=0){
                num+=temp->val;
                temp=temp->next;
            }
            ListNode *node1=new ListNode(num);
            if(head1==NULL){
                head1=node1;
                temp1=node1;
            }
            else{
                temp1->next=node1;
                temp1=temp1->next;
            }
        }
        return head1;
    }
};