class Solution {
public:
#define ll long long
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        sort(skill.begin(),skill.end());
        int n=skill.size(),tot=skill[n-1]+skill[0];
        ans=(ll)(skill[0])*skill[n-1];
        int i=1,j=n-2;
        while(i<=j){
            int k=skill[i]+skill[j];
            if(k!=tot) return -1;
            ans+=((ll)(skill[i])*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};