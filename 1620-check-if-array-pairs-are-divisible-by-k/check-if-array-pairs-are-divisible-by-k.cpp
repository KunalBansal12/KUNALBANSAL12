class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            int n=arr[i]%k;
            if(n<0){
                map[abs(n)]--;
            }
            else map[n]++;
        }
        if(map[0]%2!=0) return false;
        for(int i=1;i<=k/2;i++){
            if(map[i]!=map[k-i]) return false;
        }
        return true;
    }
};