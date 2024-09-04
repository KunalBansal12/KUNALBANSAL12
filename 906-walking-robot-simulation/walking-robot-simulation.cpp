class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>>direction={{0,1},{-1,0},{0,-1},{1,0}};
        map<pair<int,int>,int>mp;
        for(auto it:obstacles){
            mp[{it[0],it[1]}]++;
        }
        int x=0,y=0;
        int pos=0;
        int maxdist=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){
                pos++;
                if(pos==4)pos=0;
            }
            else if(commands[i]==-1){
                  pos--;
                if(pos==-1)pos=3;
            }
            else{
                for(int j=1;j<=commands[i];j++){
                    int tempx=x+direction[pos].first;
                    int tempy=y+direction[pos].second;
                    if(mp.find({tempx,tempy})==mp.end()){
                        x=tempx;
                        y=tempy;
                        int t=(x*x)+(y*y);
                        maxdist=max(maxdist,t);
                    }
                    else break;
                }
            }
        }
        return maxdist;
    }
};