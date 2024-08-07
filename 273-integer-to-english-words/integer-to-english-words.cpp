class Solution {
public:
    string numberToWords(int num) {
        vector<string>ones={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string>tens={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
         vector<string>twos={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
         vector<string>cycle={"","Thousand","Million","Billion"};
         vector<int>digits;
         if(num==0) return "Zero";
         while(num>0){
            int dig=num%10;
            num=num/10;
            digits.push_back(dig);
         }
         reverse(digits.begin(),digits.end());
         int j=digits.size()-1;
         string ans="";
         int x=0;
         while(j>=0){
            string temp="";
            for(int c=0;c<3;c++){
                if(j<0) break;
                if(c==0){
                  if(digits[j]!=0)temp = ones[digits[j]]+temp;
                  j--;
                }
                else if(c==1&&digits[j]==1){
                    temp=tens[digits[j+1]];
                    j--;
                }
                else if(c==1){
                    if(digits[j]!=0)temp = twos[digits[j]]+" "+temp;
                    j--;
                }
                else{
                    if(digits[j]!=0)temp= ones[digits[j]]+" Hundred "+ temp;
                    j--;
                }
            }
            if(temp.size()>0){
            if(x!=0){
                int n1=temp.size();
                if(temp[n1-1]==' ') temp.pop_back();
                temp=temp+" "+cycle[x]+" ";
            }
            ans=temp+ans;
            int n=ans.size();
            if(ans[n-1]==' ')ans.pop_back();
            }
            x++;
         }
         return ans;
    }
};