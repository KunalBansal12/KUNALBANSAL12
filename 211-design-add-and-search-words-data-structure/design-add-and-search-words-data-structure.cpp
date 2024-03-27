class Node{
    public:
    Node* links[26];
    bool flag=false;
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->links[word[i]-'a']==NULL){
                temp->links[word[i]-'a']=new Node();
            }
            temp=temp->links[word[i]-'a'];
        }
        temp->flag=true;
    }

    bool search(string word,Node* r){
        Node* temp=r;
        for(int i=0;i<word.size();i++){
            if(word[i]!='.'){
                if(temp->links[word[i]-'a']==NULL){
                    return false;
                }
                temp=temp->links[word[i]-'a'];
            }
            else{
                for(int j=0;j<26;j++){
                    if(temp->links[j]!=NULL){
                        bool check=search(word.substr(i+1),temp->links[j]);
                        if(check) return true;
                    }
                }
                return false;
            }
        }
        if(temp->flag) return true;
        return false;
    }
    
    bool search(string word) {
        Node* temp=root;
        return search(word,temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */