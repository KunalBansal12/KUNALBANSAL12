class Solution {
private:
    unordered_map<string, int> um;  // Dictionary words
    unordered_map<int, int> memo;   // Memoization map for storing dp results

    int solve(string& s, int ind) {
        // base condition, where recursion gets over
        if (ind >= s.size()) {
            return 0;
        }

        if (memo.find(ind) != memo.end()) {
            // Return memoized result if already computed
            return memo[ind];  
        }

        int extra = INT_MAX;
        string tmp = "";

        // Try all substrings starting from the current index
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i];
            if (um.find(tmp) != um.end()) {
                // If the substring is in the dictionary, solve for the remaining part
                extra = min(extra, solve(s, i + 1));
            }
        }

        // Consider the case where the current character is counted as extra
        // basically skipping the current ind = 0
        extra = min(extra, 1 + solve(s, ind + 1));

        // Memoize the result for the current index
        memo[ind] = extra;
        
        return memo[ind];
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        for (auto& val : dict) {
            um[val]++;
        }

        return solve(s, 0);  // Start the recursion from index 0
    }
};

// class Solution {
// public:
//     int help(int ind,string temp,string& s,unordered_map<string,int>& map,vector<int>& dp){
//         if(ind==s.length()){
//             if(!map[temp]) return temp.length();
//             return 0;
//         }
//         if(dp[ind]!=-1) return dp[ind];
//         temp+=s[ind];
//         int a=help(ind+1,temp,s,map,dp);
//         int b=help(ind+1,"",s,map,dp) + (map[temp] ? 0:temp.length());
//         return dp[ind]=min(a,b);
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_map<string,int> map;
//         vector<int> dp(s.length(),-1);
//         for(int i=0;i<dictionary.size();i++){
//             map[dictionary[i]]++;
//         }
//         return help(0,"",s,map,dp);
//     }
// };