class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0,count=0;
        int i=0,n=s.length();
        if(k==0) return 0;
        while(i<s.length() && count<3){
            if(s[i]=='a'){
                a++;
                if(a==k) count++;
            }
            else if(s[i]=='b'){
                b++;
                if(b==k) count++;
            }
            else{
                c++;
                if(c==k) count++;
            }
            i++;
        }
        if(count<3) return -1;
        int ans=i;
        int j=s.length()-1;
        i--;
        while(i>=0){
            if(s[i]=='a'){
                a--;
                if(a<k) count--;
            }
            else if(s[i]=='b'){
                b--;
                if(b<k) count--;
            }
            else{
                c--;
                if(c<k) count--;
            }
            i--;
            if(count==3){
                ans=min(ans,i+n-j);
                continue;
            }
            while(j>=0 && count<3){
                if(s[j]=='a'){
                    a++;
                    if(a==k) count++;
                }
                else if(s[j]=='b'){
                    b++;
                    if(b==k) count++;
                }
                else{
                    c++;
                    if(c==k) count++;
                }
                j--;
            }
            if(j>0) ans=min(ans,i+n-j);
        }
        return ans;
    }
};