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
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);    
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            ListNode* temp1=temp->next;
            int n=gcd(temp->val,temp1->val);
            ListNode* ne=new ListNode(n);
            temp->next=ne;
            ne->next=temp1;
            temp=temp1;
        }
        return head;
    }
};