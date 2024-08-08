class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        int i=rStart,j=cStart;
        vector<pair<int,int>>mp={{0,1},{1,0},{0,-1},{-1,0}};
        int c=1;
        int one=1;
        int direction=0;
        vector<int>t={rStart,cStart};
        ans.push_back(t);
        while(c<rows*cols){
            for(int k=0;k<one;k++){
                int index=direction%4;
                i+=mp[index].first;
                j+=mp[index].second;
                if(i>=0&&j>=0&&i<rows&&j<cols){
                    vector<int>temp={i,j};
                    ans.push_back(temp);
                    c++;
                }
            }
            direction++;
            if(direction%2==0) one++;
        }
        return ans;
    }
};