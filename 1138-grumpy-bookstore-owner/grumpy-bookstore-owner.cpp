class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0,num=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0) ans+=customers[i];
            else if(grumpy[i]==1) num+=customers[i];
            customers[i]=num;
        }
        int maxi=customers[minutes-1],i=0,j=minutes;
        while(j<customers.size()){
            maxi=max(maxi,customers[j]-customers[i]);
            i++,j++;
        }
        return ans+maxi;
    }
};