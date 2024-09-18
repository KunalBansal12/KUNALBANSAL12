class Solution {
public:
    class comp{
        public:
        bool operator()(string &a,string &b){
            return a+b>b+a;
        }
    };
    string largestNumber(vector<int>& nums) {
      vector<string>temp;
      for(int i=0;i<nums.size();i++){
        string s=to_string(nums[i]);
        temp.push_back(s);
      }  
      sort(temp.begin(),temp.end(),comp());
      string ans="";
      if(temp[0]=="0")return "0";
      for(int i=0;i<temp.size();i++){
        ans+=temp[i];
      }
      return ans;
    }
};