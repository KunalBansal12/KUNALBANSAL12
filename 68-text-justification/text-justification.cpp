class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> ans;
        while(i<words.size()){
            int j=i;
            int len=0;
            while(j<words.size() && len+words[j].size()<maxWidth){
                len+=words[j].length();
                if(j!=i) len++;
                j++;
            }
            if(i==j){
                len=maxWidth;
                j++;
            }
            string s="";
            if(j!=words.size()){
                int k=0,l=0;
                if(j!=i+1){
                    k=(maxWidth-len)/(j-i-1);
                    l=(maxWidth-len)%(j-i-1);
                    cout<<l<<endl;
                }
                for(int x=0;x<l;x++){
                    if(x!=0){
                        string n(k+2,' ');
                        s+=n;
                    }
                    s+=words[i];
                    i++;
                }
                int count=(l!=0 ? 0:1);
                while(i<j){
                    if(l!=0){
                        if(count==0){
                            string n(k+2,' ');
                            s+=n;
                            count++;
                        }
                        else{
                            string n(k+1,' ');
                            s+=n;
                        }
                    }
                    else l++;
                    s+=words[i];
                    i++;
                }
                if(s.length()<maxWidth){
                    string a(maxWidth-s.length(),' ');
                    s+=a;
                }
            }
            else{
                int count=0;
                while(i<j){
                    if(count!=0){
                        s+=" ";
                    }
                    s+=words[i];
                    count++;
                    i++;
                }
                if(s.length()<maxWidth){
                    string a(maxWidth-s.length(),' ');
                    s+=a;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};