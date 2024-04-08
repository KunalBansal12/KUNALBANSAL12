class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n=students.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(students[i]==sandwiches[j]){
                j++;
                continue;
            }
            q.push(students[i]);
        }
        if(q.size()==0) return 0;
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                if(q.front()==sandwiches[j]){
                    q.pop();
                    j++;
                    continue;
                }
                q.push(q.front());
                q.pop();
            }
            if(n==q.size()) return n;
        }
        return q.size();
    }
};