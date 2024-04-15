#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        unordered_map<ll,int> map;
        int primes[]={2,3,5};
        pq.push(1);
        while(n>0){
            ll p=pq.top();
            pq.pop();
            n--;
            if(n==0) return p;
            for(int i=0;i<3;i++){
                if(!map[p*primes[i]]){
                    pq.push(p*primes[i]);
                    map[p*primes[i]]=1;
                }
            }
        }
        return -1;
    }
};

