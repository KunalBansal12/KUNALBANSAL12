class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int elim=nums.size()-k;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || elim==0){
                st.push(nums[i]);
                continue;
            }
            if(st.top()<=nums[i]){
                st.push(nums[i]);
            }
            else{
                while(elim && st.size() && st.top()>nums[i]){
                    st.pop();
                    elim--;
                }
                st.push(nums[i]);
            }
        }
        while(elim && st.size()){
            st.pop();
            elim--;
        }
        vector<int> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};