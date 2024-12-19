class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,num=0;
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
            if(arr[i]<i) num--;
            if(!map[i]){
                num++;
            }
            else{
                if(num==0) ans++;
            }
        }
        return ans;
    }
};