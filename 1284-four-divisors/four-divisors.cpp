class Solution {
public:
    void divisor(int n, int &sum){
        int count=0,s=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                count+=1,s+=i;
                if(n/i!=i) count+=1,s+=(n/i);
            }
        }
        if(count==4) sum+=s;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) divisor(nums[i], sum);
        return sum;
    }
};