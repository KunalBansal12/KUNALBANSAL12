class Solution {
public:
    int countPairs(vector<int>& nums) {
        vector<string> s;
        for(int i=0;i<nums.size();i++) s.push_back(to_string(nums[i]));
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=0;
                string n=s[i],m=s[j];
                int k=n.length()-1,l=m.length()-1;
                char difn=' ',difm=' ';
                while(k>=0 && l>=0){
                    if(n[k]!=m[l] && diff==2){
                        diff++;
                        break;
                    }
                    else if(n[k]!=m[l]){
                        if(diff==0){
                            diff++;
                            difn=n[k];
                            difm=m[l];
                        }
                        else if(diff==1){
                            if(difn!=m[l] || difm!=n[k]) break;
                            diff++;
                        }
                    }
                    k--;
                    l--;
                }
                if(diff==1){
                    if(k!=-1 && l==-1){
                        if(n[0]==difm && difn=='0'){
                            while(k!=0){
                                if(n[k]!='0') break;
                                else k--;
                            }
                            if(k==0) ans++;
                        }
                    }
                    else if(l!=-1 && k==-1){
                        if(m[0]==difn && difm=='0'){
                            while(l!=0){
                                if(m[l]!='0') break;
                                else l--;
                            }
                            if(l==0) ans++;
                        }
                    }
                }
                else if(diff==2 || diff==0){
                    if(l==-1 && k==-1) ans++;
                }
                else if(diff!=2 && diff!=0) continue;
            }
        }
        return ans;
    }
};