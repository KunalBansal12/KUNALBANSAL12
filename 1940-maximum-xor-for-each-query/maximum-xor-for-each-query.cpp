class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xo=0;
        for(int i=0;i<nums.size();i++){
            xo=xo^nums[i];
        }
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            int n=0;
            // cout<<(1<<1)<<endl;
            // cout<<i<<" "<<xor<<endl;
            for(int j=maximumBit-1;j>=0;j--){
                if(((1<<j)&xo)==0){
                    // cout<<i<<" "<<j<<" "<<xo<<endl;
                    n=n|(1<<j);
                    // cout<<(1>>j)<<endl;
                }
            }
            ans.push_back(n);
            xo=xo^nums[i];
        }
        return ans;
    }
};