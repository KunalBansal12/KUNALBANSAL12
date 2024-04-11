class Solution {
public:
    string orderlyQueue(string s, int x) {
        if(x>1){
            sort(s.begin(),s.end());
            return s;
        }
        int n=s.length(),i=0,j=1;
        char c=s[0];
        while(j<s.length()){
            if(s[j]>c){
                j++;
                continue;
            }
            else if(s[j]<c){
                c=s[j];
                i=j;
                j++;
            }
            else if(s[j]==c){
                int k=i,l=j;
                while(k<n && l<n){
                    if(s[k]>s[l]){
                        i=j;
                    }
                    else if(s[k]<s[l]){
                        break;
                    }
                    k=(k+1)%n;
                    l=(l+1)%n;
                    if(k==i) break;
                }
                j++;
            }
        }
        string ans="";
        for(int k=0;k<n;k++){
            ans+=s[(i+k)%n];
        }
        return ans;
    }
};