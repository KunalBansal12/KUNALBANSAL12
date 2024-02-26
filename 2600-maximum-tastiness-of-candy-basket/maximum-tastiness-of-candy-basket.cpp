class Solution {
public:
    bool help(int mid,int k,vector<int>& price){
        int s=price[0],count=1;
        for(int i=1;i<price.size();i++){
            if(price[i]-s>=mid){
                count++;
                s=price[i];
            }
            if(count==k) return 1;
        }
        return 0;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size(),l=0,h=price[n-1]-price[0],ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(help(mid,k,price)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};