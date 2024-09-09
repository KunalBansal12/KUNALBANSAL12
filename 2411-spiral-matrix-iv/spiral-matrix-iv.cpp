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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int row=0,col=0;
        while(head!=NULL){
            for(int i=col;i<n-col;i++){
                ans[row][i]=head->val;
                head=head->next;
                if(head==NULL) return ans;
            }
            for(int i=row+1;i<m-row;i++){
                ans[i][n-col-1]=head->val;
                head=head->next;
                if(head==NULL) return ans;
            }
            for(int i=n-col-2;i>=col;i--){
                ans[m-row-1][i]=head->val;
                head=head->next;
                if(head==NULL) return ans;
            }
            for(int i=m-row-2;i>=row+1;i--){
                ans[i][col]=head->val;
                head=head->next;
                if(head==NULL) return ans;
            }
            row++;
            col++;
        }
        return ans;
    }
};