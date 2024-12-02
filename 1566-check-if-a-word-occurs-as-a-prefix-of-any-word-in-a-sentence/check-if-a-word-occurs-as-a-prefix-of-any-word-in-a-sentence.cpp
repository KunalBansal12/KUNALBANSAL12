class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans=0;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ') continue;
            int j=0,k=i;
            bool check=true;
            ans++;
            // cout<<i<<" "<<ans<<endl;
            while(j<searchWord.size() && k<sentence.size() && sentence[k]!=' '){
                if(searchWord[j]==sentence[k] && check){
                    j++;
                    k++;
                }
                else{
                    check=false;
                    k++;
                }
                if(j==searchWord.size()) return ans;
            }
            i=k-1;
        }
        return -1;
    }
};