class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0; // free start
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[j] = max saving if other finger is at j
        vector<int> dp(26, 0);
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            int cur = word[i] - 'A';
            int next = word[i + 1] - 'A';
            
            int d = dist(cur, next);
            res += d;

            int best = 0;
            for (int j = 0; j < 26; j++) {
                dp[cur] = max(dp[cur], dp[j] + d - dist(j, next));
            }
        }

        int maxSave = 0;
        for (int x : dp) maxSave = max(maxSave, x);

        return res - maxSave;
    }
};