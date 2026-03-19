class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        vector<vector<int>> prefixCount(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int val = 0;
                int cnt = 0;

                if(grid[i][j] == 'X') {
                    val = 1;
                    cnt = 1;
                }
                else if(grid[i][j] == 'Y') {
                    val = -1;
                    cnt = 1;
                }

                prefixSum[i][j] = val;
                prefixCount[i][j] = cnt;

                if(i > 0) {
                    prefixSum[i][j] += prefixSum[i-1][j];
                    prefixCount[i][j] += prefixCount[i-1][j];
                }
                if(j > 0) {
                    prefixSum[i][j] += prefixSum[i][j-1];
                    prefixCount[i][j] += prefixCount[i][j-1];
                }
                if(i > 0 && j > 0) {
                    prefixSum[i][j] -= prefixSum[i-1][j-1];
                    prefixCount[i][j] -= prefixCount[i-1][j-1];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // sum == 0 → X == Y
                // count > 0 → at least one X or Y exists
                if(prefixSum[i][j] == 0 && prefixCount[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};