class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty()) st.push({heights[i],i});
            else if(st.top().first<heights[i]){
                int ans1=0;
                while(st.size() && st.top().first<heights[i]){
                    st.pop();
                    ans1++;
                }
                if(st.size()) ans[i]=ans1+1;
                else ans[i]=ans1;
                st.push({heights[i],i});
            }
            else if(st.top().first>=heights[i]){
                ans[i]=1;
                st.push({heights[i],i});
            }
        }
        return ans;
    }
};