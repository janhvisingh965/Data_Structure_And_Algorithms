class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> temp;

                // collect k x k elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }

                // sort the values
                sort(temp.begin(), temp.end());

                int mini = INT_MAX;

                // find min difference between DISTINCT elements
                for (int t = 1; t < temp.size(); t++) {
                    if (temp[t] != temp[t - 1]) {   // <-- important fix
                        mini = min(mini, temp[t] - temp[t - 1]);
                    }
                }

                // if all values same
                if (mini == INT_MAX) mini = 0;

                ans[i][j] = mini;
            }
        }

        return ans;
    }
};