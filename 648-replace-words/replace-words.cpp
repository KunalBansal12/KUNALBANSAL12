class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,bool> map;
        for(int i=0;i<dictionary.size();i++){
            map[dictionary[i]]=true;
        }
        string ans="";
        string help="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                help="";
                ans+=' ';
                continue;
            }
            else{
                help+=sentence[i];
                ans+=sentence[i];
                if(map[help]==true){
                    help="";
                    while(i<sentence.length() && sentence[i]!=' ') i++;
                    i--;
                }
            }
        }
        return ans;
    }
};