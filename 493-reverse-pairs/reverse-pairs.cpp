#define ll long long
class Solution {
public:
    int help(vector<int>& nums,int si,int mid,int ei){
        int st=mid+1,end=ei;
        int j=mid;
        while(st<=end){
            int nmid=st+(end-st)/2;
            ll val=(ll)2*(ll)nums[nmid];
            if(val<(ll)nums[si]){
                j=max(j,nmid);
                st=nmid+1;
            }
            else end=nmid-1;
        }
        return j-mid;
    }

    int merge(vector<int>& nums,int si,int mid,int ei){
        if(si>=ei) return 0;
        int ans=0;
        for(int i=si;i<=mid;i++){
            ans+=help(nums,i,mid,ei);
        }
        sort(nums.begin()+si,nums.begin()+ei+1);
        return ans;
    }

    int mergesort(vector<int>& nums,int si,int ei){
        if(si>=ei) return 0;
        int mid=si+(ei-si)/2;
        int n1=mergesort(nums,si,mid);
        int n2=mergesort(nums,mid+1,ei);
        int ans=merge(nums,si,mid,ei);
        return n1+n2+ans;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};