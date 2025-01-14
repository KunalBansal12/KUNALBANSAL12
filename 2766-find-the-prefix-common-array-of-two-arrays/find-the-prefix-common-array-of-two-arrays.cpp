class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int> map;
        int num=0;
        for(int i=0;i<n;i++){
            if(map[A[i]]) num++;
            else map[A[i]]++;
            if(map[B[i]]) num++;
            else map[B[i]]++;
            A[i]=num;
        }
        return A;
    }
};