class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1,num=1,n=nums.size(),d=0,inc=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                if(d==0){
                    d=1;
                    num++;
                    inc=1;
                }
            }
            else if(nums[i]==nums[i-1]+1){
                num++;
            }
            else if(nums[i]==nums[i-1]+2){
                if(inc){
                    inc=0;
                    num++;
                    d=0;
                }
                else{
                    inc=0;
                    num=2;
                    d=0;
                    int k=0,nu=0,j=i-2;
                    while(j>0){
                        if(nums[j]==nums[j+1]-1) num++;
                        else if(nums[j]==nums[j+1]){
                            if(k==0){
                                k=1;
                                num++;
                                nu=nums[j];
                            }
                            else if(nu!=nums[j]) break;
                        }
                        else break;
                        j--;
                    }
                }
            }
            else{
                d=0;
                num=1;
                inc=1;
            }
            ans=max(ans,num);
        }
        return ans;
    }
};