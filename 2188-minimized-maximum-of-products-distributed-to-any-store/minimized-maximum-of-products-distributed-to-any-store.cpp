class Solution {
public:
    int bs(int mid,vector<int>& quantities){
        int n=0;
        for(int i=0;i<quantities.size();i++){
            n+=(quantities[i]+mid-1)/mid;
        }
        return n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int s=quantities.size(),low=1,high=quantities[s-1],ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int t=bs(mid,quantities);
            if(t>n){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};