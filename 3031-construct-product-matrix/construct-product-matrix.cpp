class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        vector<int> arr;
        for (auto &row : grid) {
            for (int x : row) arr.push_back(x % mod);
        }

        int sz = arr.size();
        vector<int> prefix(sz, 1), suffix(sz, 1);

        for (int i = 1; i < sz; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }

        for (int i = sz - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }

        vector<int> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = (prefix[i] * suffix[i]) % mod;
        }

        vector<vector<int>> ans(m, vector<int>(n));
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = res[k++];
            }
        }

        return ans;
    }
};