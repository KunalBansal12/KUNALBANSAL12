class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1)return 1;
        unordered_map<int,bool>mp;
        for(int i=1;i<=n;i++) mp[i]=false;
        int i=1;
        int c=n;
        while(true){
            for(int j=1;j<k;j++){
                while(mp[i]){
                    i++;
                  if(i==n+1)i=1;
                }
                i++;
                 if(i==n+1)i=1;
            }
            while(mp[i]){
                 i++;
              if(i==n+1)i=1;
            }
            mp[i]=true;
            c--;
            if(c==1) break;
            i++;
            if(i==n+1)i=1;
        }
        for(auto it:mp){
            if(it.second==false) return it.first;
        }
        return 0;
    }
};