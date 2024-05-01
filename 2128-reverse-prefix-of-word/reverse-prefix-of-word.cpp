class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.length()){
            if(word[i]==ch) break;
            i++;
        }
        if(i==word.length()) return word;
        reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};