class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size(),left=0,ans=INT_MAX;
        while(left<n-1 && arr[left+1]>=arr[left]) left++;
        if(left==n-1) return 0;
        ans=min(ans,n-left-1);
        int right=n-1;
        while(right>0 && arr[right-1]<=arr[right]) right--;
        ans=min(ans,right);
        int i=0;
        while(i<=left){
            while(right<n && arr[i]>arr[right]) right++;
            ans=min(ans,right-i-1); 
            i++;
        }
        return ans;
    }
};