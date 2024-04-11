class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(k==nums.length()) return "0";
        if(k==0) return nums;
        stack<char> st;
        for(int i=0;i<nums.length();i++){
            if(k==0) st.push(nums[i]);
            else if(st.empty()){
                st.push(nums[i]);
            }
            else if(st.top()<=nums[i]) st.push(nums[i]);
            else if(st.top()>nums[i]){
                while(k>0 && st.size() && st.top()>nums[i]){
                    st.pop();
                    k--;
                }
                st.push(nums[i]);
            }
            if(st.size() == 1 && nums[i] == '0')
                st.pop();
        }
        string ans="";
        while(k && st.size()){
            k--;
            st.pop();
        }
        int n=st.size();
        for(int i=0;i<n;i++){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==0) return "0";
        return ans;
    }
};