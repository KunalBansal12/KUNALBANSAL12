class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            if(map[2*arr[i]]>0) return true;
            if(arr[i]%2==0 && map[arr[i]/2]>0) return true;
            map[arr[i]]++;
        }
        return false;
    }
};