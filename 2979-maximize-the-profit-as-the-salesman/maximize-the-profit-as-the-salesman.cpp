class Solution {
public:
    int helper(vector<int>& dp, vector<vector<int>>& v, int n) {
        vector<int> s, e; 
        for (auto i : v) {
            s.push_back(i[0]);
            e.push_back(i[1]);
        }

        for (int i = v.size() - 1; i >= 0; i--) {
            int check = upper_bound(s.begin(), s.end(), e[i]) - s.begin();
            dp[i] = max(v[i][2] + dp[check], dp[i + 1]);
        }

        return (*max_element(dp.begin(), dp.end()));
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size() + 1, 0);
        sort(offers.begin(), offers.end());
        return helper(dp, offers, n);
    }
};