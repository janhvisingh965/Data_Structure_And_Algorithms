class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // build heights
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }

            // sort heights (simulate column rearrangement)
            vector<int> temp = height;
            sort(temp.begin(), temp.end(), greater<int>());

            // calculate max area
            for (int j = 0; j < m; j++) {
                maxArea = max(maxArea, temp[j] * (j + 1));
            }
        }

        return maxArea;
    }
};