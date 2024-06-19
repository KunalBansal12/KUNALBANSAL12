class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total =(1LL)*m*k;
        int l = 0;
        int n = bloomDay.size();
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size() < total) return -1;
        while(l <= h){
            int mid = (l+h)/2;
            int count = 0;
            int a = 0;
            for(int i = 0 ; i < n ; i++){
                if(bloomDay[i] <= mid){
                    count++;
                    if(count%k == 0)
                    a++;
                }
                else
                count = 0;
            }
            if(a >= m)
            h = mid-1;
            else
            l = mid+1;
        }
        return l;
        // return h;
    }
};