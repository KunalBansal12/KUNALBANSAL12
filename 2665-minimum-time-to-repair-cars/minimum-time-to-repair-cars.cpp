class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars){
        long long count = 0;
        for(int i=0; i<ranks.size(); i++){
            long long temp;
            temp = mid/ranks[i];
            count += sqrt(temp);
        }
        if(count >= cars){
            return true;
        }
        return false;
    }


    long long repairCars(vector<int>& ranks, int cars) {
        int mini= ranks[0];
        for(int i=1;i<ranks.size();i++){
            mini = min(mini,ranks[i]);
        }
        long long start = 1, end = ((long long)mini*(long long)cars*(long long)cars);
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end-start)/2;
            if(isPossible(ranks, mid, cars)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};