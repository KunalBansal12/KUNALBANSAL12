class Node{
    public:
    Node* links[26];
    bool flag=false;
    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    bool containsKeyn(int c){
        return (links[c]!=NULL);
    }
    void putKey(char c,Node* temp){
        links[c-'a']=temp;
    }
    Node* getKey(char c){
        return links[c-'a'];
    }
    Node* getKeyn(int c){
        return links[c];
    }
};

class MagicDictionary {
    void insert(string s){
        Node* temp=root;
        for(int i=0;i<s.length();i++){
            if(!temp->containsKey(s[i])){
                temp->putKey(s[i],new Node());
            }
            temp=temp->getKey(s[i]);
        }
        temp->flag=true;
    }
public:
    Node* root;
    MagicDictionary() {
        root=new Node();
    }
    
    void buildDict(vector<string> d) {
        for(int i=0;i<d.size();i++){
            insert(d[i]);
        }
    }

    bool help(Node* temp,int j,string s){
        if(j==s.length()){
            if(temp->flag) return true;
            return false;
        }
        for(int i=j;i<s.length();i++){
            if(!temp->containsKey(s[i])) return false;
            temp=temp->getKey(s[i]);
        }
        if(temp->flag) return true;
        return false;
    }
    
    bool search(string s) {
        Node* temp=root;
        int i=0;
        while(i<s.length()){
            for(int j=0;j<26;j++){
                if(j==s[i]-'a') continue;
                bool check=false;
                if(temp->containsKeyn(j)){
                    bool a=help(temp->getKeyn(j),i+1,s);
                    if(a==true) check=true;
                }
                if(check==true) return true;
            }
            if(temp->containsKey(s[i])) temp=temp->getKey(s[i]);
            else return false;
            i++;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */