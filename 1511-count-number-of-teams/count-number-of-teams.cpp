class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=1;i<n-1;++i){
            int lsmall=0;int lhigh=0;int rsmall = 0;int rhigh = 0;
            for(int j=0;j<i;++j){
                if(rating[j]<rating[i]){
                    ++lsmall;
                }
                else if(rating[j]>rating[i]){
                    ++lhigh;
                }
            }
            for(int j=i+1;j<n;++j){
                if(rating[j]<rating[i]){
                    ++rsmall;
                    }
                else if(rating[j]>rating[i]){
                    ++rhigh;
                }
            }
            ans += ((lsmall*rhigh)+(lhigh*rsmall));
        }
        return ans;
        // int ans=0;
        // for(int i=0;i<rating.size()-2;i++){
        //     for(int j=i+1;j<rating.size()-1;j++){
        //         for(int k=j+1;k<rating.size();k++){
        //             if(rating[i]>rating[j] && rating[j]>rating[k]) ans++;
        //             if(rating[i]<rating[j] && rating[j]<rating[k]) ans++;
        //         }
        //     }
        // }
        // return ans;
    }
};