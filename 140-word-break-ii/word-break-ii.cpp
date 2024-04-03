class Node{
    public:
    Node* links[26];
    bool flag=false;
    bool containskey(char c){
        return (links[c-'a']!=NULL);
    }
    void putkey(char c,Node* temp){
        links[c-'a']=temp;
    }
    Node* getkey(char c){
        return links[c-'a'];
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }

    void insert(string s){
        Node* temp=root;
        for(int i=0;i<s.length();i++){
            if(!temp->containskey(s[i])){
                temp->putkey(s[i],new Node());
            }
            temp=temp->getkey(s[i]);
        }
        temp->flag=true;
    }
};

class Solution {
public:
    void help(string s,int ind,Trie& trie,vector<string>& ans,string a){
        if(ind==s.length()){
            ans.push_back(a);
            return;
        }
        Node* temp=trie.root;
        while(ind<s.length()){
            if(temp->containskey(s[ind])){
                temp=temp->getkey(s[ind]);
                a+=s[ind];
                if(temp->flag){
                    if(ind==s.length()-1){
                        ans.push_back(a);
                        return;
                    }
                    a+=" ";
                    help(s,ind+1,trie,ans,a);
                    a.pop_back();
                }
            }
            else{
                // if(temp->flag){
                //     a+=" ";
                //     help(s,ind,trie,ans,a);
                // }
                break;
            }
            ind++;
        }
        if(ind==s.length() && temp->flag) ans.push_back(a);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i=0;i<wordDict.size();i++) trie.insert(wordDict[i]);
        vector<string> ans;
        help(s,0,trie,ans,"");
        return ans;
    }
};