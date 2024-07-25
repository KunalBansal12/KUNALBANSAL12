class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> count(2*50000+1,0);
        for(int num: nums){
            count[num+50000]++;
        }
        int ind=0;
        for(int i=0;i<count.size();i++){
            int freq=count[i];
            while(freq!=0){
                nums[ind]=i-50000;
                ind++;
                freq--;
            }
        }
        return nums;
    }
};