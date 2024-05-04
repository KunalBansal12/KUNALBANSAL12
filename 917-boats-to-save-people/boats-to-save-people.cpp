class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j){
            if(i==j){
                ans++;
                return ans;
            }
            else if(people[i]+people[j]>limit){
                j--;
                ans++;
            }
            else{
                j--,i++,ans++;
            }
        }
        return ans;
    }
};