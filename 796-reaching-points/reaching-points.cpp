class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx==tx && sy==ty) return true;
        if(sx>tx || sy>ty) return false;
        if(tx==ty) return false;
        while(sx<=tx && sy<=ty){
            if(sx==tx && sy==ty) return true;
            if(tx==ty) return false;
            if(tx==sx){
                if((ty-sy)%tx==0) return true;
                else return false;
            }
            else if(ty==sy){
                if((tx-sx)%ty==0) return true;
                else return false;
            }
            if(tx>ty){
                if(tx%ty!=0) tx=tx%ty;
                else tx=(tx%ty)+ty;
            }
            else if(ty>tx){
                if(ty%tx!=0) ty=ty%tx;
                else ty=(ty%tx)+tx;
            }
        }
        return false;
    }
};