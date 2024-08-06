class Solution {
public:
    int minimumPushes(string word) {
        int tot=8,ans=0;
        int n=word.length();
        if(n<=8) return n;
        unordered_map<int,int> map;
        unordered_map<char,int> map1;
        for(int i=0;i<n;i++){
            map1[word[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:map1){
            pq.push({it.second,it.first});
        }
        map[1]=8;
        map[2]=8;
        map[3]=8;
        map[4]=2;
        int j=0;
        int a[4]={1,2,3,4};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(map[a[j]]){
                ans+=(it.first*a[j]);
                map[a[j]]--;
            }
            else{
                j++;
                ans+=(it.first*a[j]);
                map[a[j]]--;
            }
        }
        return ans;
    }
};