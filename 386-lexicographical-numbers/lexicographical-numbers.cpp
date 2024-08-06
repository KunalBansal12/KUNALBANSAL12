class Solution {
public:
    void help(int num,int n,vector<int>& ans){
        int i;
        if(num==0) i=1;
        else i=0;
        for(i;i<10;i++){
            int k=num*10+i;
            if(k<=n){
                ans.push_back(k);
                help(k,n,ans);
            }
            else return;
        }
        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        help(0,n,ans);
        return ans;
    }
};