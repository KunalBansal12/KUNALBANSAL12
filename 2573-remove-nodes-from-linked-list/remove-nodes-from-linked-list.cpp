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
    pair<ListNode*,int> removehelper(ListNode *head){
        if(head->next==NULL){
            pair<ListNode*,int> ans;
            ans.first=head;
            ans.second=head->val;
            return ans;
        }
        pair<ListNode*,int> smallans=removehelper(head->next);
        if(smallans.second>head->val){
            head->next=NULL;
            return smallans;
        }
        head->next=smallans.first;
        smallans.first=head;
        smallans.second=head->val;
        return smallans;
    }

    ListNode* removeNodes(ListNode* head) {
        return removehelper(head).first;
    }
};