class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>floyd(26,vector<int>(26,INT_MAX));
       for(int i=0;i<original.size();i++){
               floyd[original[i]-'a'][changed[i]-'a'] = min(cost[i],floyd[original[i]-'a'][changed[i]-'a']);
       } 
       for(int i=0;i<26;i++){
             floyd[i][i]=0;
       }
       for(int k=0;k<26;k++){
           for(int i=0;i<26;i++){
               for(int j=0;j<26;j++){
                   if(floyd[i][k]!=INT_MAX&&floyd[k][j]!=INT_MAX){
                   floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
                   }
               }
           }
       }
       long long ans=0;
       for(int i=0;i<source.length();i++){
           if(source[i]==target[i]) continue;
           else{
               if(floyd[source[i]-'a'][target[i]-'a']==INT_MAX){
                   ans=-1;
                   break;
               }
               ans+=floyd[source[i]-'a'][target[i]-'a'];
           }
       }
       return ans;
    }
};