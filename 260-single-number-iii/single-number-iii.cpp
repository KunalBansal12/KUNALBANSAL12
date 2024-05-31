class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size(),XOR=0;
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }
        int bit=0;
        for(int i=0;i<32;i++){
            if(((XOR>>i)&1)!=0){
                bit=i;
                break;
            }
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if((nums[i]&(1<<bit))==0) a=a^nums[i];
            else b=b^nums[i];
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};