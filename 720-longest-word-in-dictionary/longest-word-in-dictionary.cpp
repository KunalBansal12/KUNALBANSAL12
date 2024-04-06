class Node{
    public:
    Node* links[26];
    bool flag=false;
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    string insert(string s,string a){
        Node* temp=root;
        int num=0;
        for(int i=0;i<s.length();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a']=new Node();
                if(i==s.length()-1) num++;
                a+=s[i];
            }
            else if(temp->links[s[i]-'a']->flag){
                num++;
                a+=s[i];
            }
            temp=temp->links[s[i]-'a'];
        }
        temp->flag=true;
        if(num==s.length()) return a;
        return "";
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        Trie trie;
        string ans="";
        for(int i=0;i<words.size();i++){
            string a=trie.insert(words[i],"");
            if(a.length()>ans.length()) ans=a;
        }
        return ans;
    }
};