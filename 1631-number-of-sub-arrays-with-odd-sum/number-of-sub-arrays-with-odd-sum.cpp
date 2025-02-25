class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum=0;
        int odd=0,even=0;
        long long count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==1) count++;
            if(sum%2==0){
                count+=odd;
                even++;
            }
            else if(sum%2==1){
                count+=even;
                odd++;
            }
        }
        return count%1000000007;
    }
};