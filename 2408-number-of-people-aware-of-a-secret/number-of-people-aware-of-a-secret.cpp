class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // day 1, one person learns the secret

        long long sharing = 0; // track how many can share

        for (int day = 2; day <= n; day++) {
            // add people who can start sharing today
            if (day - delay >= 1) 
                sharing = (sharing + dp[day - delay]) % MOD;

            // remove people who forget today
            if (day - forget >= 1) 
                sharing = (sharing - dp[day - forget] + MOD) % MOD;

            // those sharing will pass secret today
            dp[day] = sharing;
        }

        // count people who still remember on day n
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};
