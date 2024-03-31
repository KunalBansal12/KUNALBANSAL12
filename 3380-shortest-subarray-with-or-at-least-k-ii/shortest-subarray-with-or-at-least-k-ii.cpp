class Solution {
public:
    void put(unordered_map<int,int>& map,int num){
        int i=0;
        while(num>0){
            if(num%2==1) map[i]++;
            i++;
            num=num/2;
        }
    }

    void del(int num,unordered_map<int,int>& map,int& ans){
        int i=0;
        while(num>0){
            if(num%2==1){
                map[i]--;
                if(map[i]==0) ans-=pow(2,i);
            }
            i++;
            num=num/2;
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=INT_MAX,num=0,si=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=k) return 1;
            num=num | nums[i];
            put(map,nums[i]);
            if(num>=k){
                ans=min(ans,i-si+1);
                while(num>=k && i>si){
                    del(nums[si],map,num);
                    si++;
                    if(num>=k) ans=min(ans,i-si+1);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};