    vector<int> dp(1001,-1);
class Solution {
public:
    bool backtrack(int num,int target,int sum,int number,int power){
        if(num==0){
            if(sum+number==target) return true;
            else return false;
        }
        number+=(num%10)*pow(10,power);
        num=num/10;
        bool check=backtrack(num,target,sum,number,power+1);
        bool check2=backtrack(num,target,sum+number,0,0);
        return check|check2;        
    }

    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            // cout<<dp[i]<<endl;
            if(dp[i]==0) continue;
            else if(dp[i]==1) ans+=i*i;
            else{
                bool l=backtrack(i*i,i,0,0,0);
                if(l){
                    dp[i]=1;
                    ans+=i*i;
                }
                else dp[i]=0;
            }
        }
        return ans;
    }
};