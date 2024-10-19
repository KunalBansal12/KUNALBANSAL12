class Solution {
public:
    char findKthBit(int n, int k) {
        int num=0;
        k--;
        while(n>1){
            int j=pow(2,n)-2;
            j=j/2;
            if(k>j) num++;
            else if(k==j){
                num++;
                break;
            }
            if(k<j) k=k%j;
            else k=j-k%(j+1)-1;
            // cout<<n<<" "<<k<<endl;
            n--;
        }
        if(num%2==0) return '0';
        return '1';
    }
};