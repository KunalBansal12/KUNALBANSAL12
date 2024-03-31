class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum=0,n=possible.size();
        vector<int> pre(n,0);
        for(int i=0;i<n;i++){
            if(possible[i]==0) sum--;
            else sum++;
            pre[i]=sum;
        }
        for(int i=0;i<n-1;i++){
            if(2*pre[i]>pre[n-1]) return i+1;
        }
        return -1;
    }
};