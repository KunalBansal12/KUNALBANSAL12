class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        if(n==1) return 0;
        vector<int> a(n,0),b(n,0);
        for(int i=0;i<n;i++){
            if(i==0 && s[i]=='a') while(i<n && s[i]=='a') i++;
            if(i==n) break;
            if(s[i]=='a') a[i]=a[i-1]+1;
            else if(i==0 && s[i]=='b') continue;
            else a[i]=a[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1 && s[i]=='b') while(i>=0 && s[i]=='b') i--;
            if(i<0) break;
            if(s[i]=='b') b[i]=b[i+1]+1;
            else if(i==n-1 && s[i]=='a') continue;
            else b[i]=b[i+1];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,a[n-1]-a[i]+b[0]-b[i]);
        }
        return ans;
    }
};