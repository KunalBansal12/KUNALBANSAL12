// hashmap approach

class MyCalendar {
public:
     map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
         mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            sum=sum+it->second;
            if(sum>1)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

//  Segment tree approach
// class MyCalendar {
// private:
//     unordered_map<int,int> seg,lazy;
//     void update(int ind,int low,int high,int l,int r){
//         if(lazy[ind]!=0){
//             seg[ind]+=lazy[ind];
//             if(low!=high){
//                 lazy[2*ind+1]+=lazy[ind];
//                 lazy[2*ind+2]+=lazy[ind];
//             }  
//             lazy[ind]=0;
//         }
//         if(r<low || l>high || l>r) return;
//         if(low>=l && high<=r){
//             seg[ind]+=1;
//             if(low!=high){
//                 lazy[2*ind+1]+=1;
//                 lazy[2*ind+2]+=1;
//             }
//             return;
//         }
//         int mid=low+(high-low)/2;
//         update(2*ind+1,low,mid,l,r);
//         update(2*ind+2,mid+1,high,l,r);
//         seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
//         return;
//     }

//     // int query(int ind,int low,int high,int l,int r){
//     //     if(lazy[ind]!=0){
//     //         seg[ind]+=lazy[ind];
//     //         if(low!=high){
//     //             lazy[2*ind+1]+=lazy[ind];
//     //             lazy[2*ind+2]+=lazy[ind];
//     //         }  
//     //         lazy[ind]=0;
//     //     }
//     //     if(r<low || l>high || l>r) return 0;
//     //     if(low>=l && high<=r) return seg[ind];
//     //     int mid=low+(high-low)/2;
//     //     int l1=query(2*ind+1,low,mid,l,r);
//     //     int r1=query(2*ind+2,mid+1,high,l,r);
//     //     return max(l1,r1);
//     // }

//     bool doubl(int ind,int low,int high, int l,int r){
//         if(lazy[ind]!=0){
//             seg[ind]+=lazy[ind];
//             if(low!=high){
//                 lazy[2*ind+1]+=lazy[ind];
//                 lazy[2*ind+2]+=lazy[ind];
//             }  
//             lazy[ind]=0;
//         }
//         if(r<low || l>high || l>r) return false;
//         if(low>=l && high<=r){
//             if(seg[ind]>=1) return true;
//             return false;
//         }
//         int mid=low+(high-low)/2;
//         bool l1=doubl(2*ind+1,low,mid,l,r);
//         bool r1=doubl(2*ind+2,mid+1,high,l,r);
//         return l1 || r1;
//     }
// public:
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         bool doub=doubl(0,0,1e9,start,end-1);
//         if(doub) return false;
//         update(0,0,1e9,start,end-1);
//         return true;
//     }
// };

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */