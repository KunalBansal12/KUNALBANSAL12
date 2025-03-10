#define ll long long
class Solution {
public:
    bool check(int i,int mid,vector<vector<int>>& count,int& k){
        for(int j=0;j<5;j++){
            if(count[mid][j]-count[i][j]==0) return false;
        }
        // if(count[mid][5]-count[i][5]!=k) return false;
        return true;
    }
    
    int highest(int i,int& k,vector<vector<int>>& count){
        int low=i+1,high=count.size()-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(count[mid][5]-count[i][5]>k) high=mid-1;
            else if(count[mid][5]-count[i][5]<k) low=mid+1;
            else{
                bool ok=check(i,mid,count,k);
                if(ok){
                    low=mid+1;
                    ans=mid;
                }
                else low=mid+1;
            }
        }
        return ans;
    }
    
    int lowest(int i,int& k,vector<vector<int>>& count){
        int low=i+1,high=count.size()-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(count[mid][5]-count[i][5]>k) high=mid-1;
            else if(count[mid][5]-count[i][5]<k) low=mid+1;
            else{
                bool ok=check(i,mid,count,k);
                if(ok){
                    high=mid-1;
                    ans=mid;
                }
                else low=mid+1;
            }
        }
        return ans;
    }
    
    long long countOfSubstrings(string word, int k) {
        ll ans=0;
        vector<vector<int>> count(word.length()+1,vector<int>(6,0));
        for(int i=0;i<word.size();i++){
            if(word[i]=='a') count[i+1][0]+=1;
            else if(word[i]=='e') count[i+1][1]+=1;
            else if(word[i]=='i') count[i+1][2]+=1;
            else if(word[i]=='o') count[i+1][3]+=1;
            else if(word[i]=='u') count[i+1][4]+=1;
            else count[i+1][5]+=1;
            count[i+1][0]+=count[i][0];
            count[i+1][1]+=count[i][1];
            count[i+1][2]+=count[i][2];
            count[i+1][3]+=count[i][3];
            count[i+1][4]+=count[i][4];
            count[i+1][5]+=count[i][5];
        }
        for(int i=0;i<word.length();i++){
            int j=lowest(i,k,count);
            if(j==-1) continue;
            int l=highest(i,k,count);
            ans+=l-j+1;
        }
        return ans;
    }
};