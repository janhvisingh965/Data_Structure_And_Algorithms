class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        vector<vector<int>> pos(temp.size());

        for (int i = 0; i < n; i++) {
            int id = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            pos[id].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int id = lower_bound(temp.begin(), temp.end(), nums[q]) - temp.begin();
            vector<int>& vec = pos[id];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int minDist = INT_MAX;

            int right = (idx + 1) % vec.size();
            int j = vec[right];
            int diff = abs(q - j);
            minDist = min(minDist, min(diff, n - diff));

            int left = (idx - 1 + vec.size()) % vec.size();
            j = vec[left];
            diff = abs(q - j);
            minDist = min(minDist, min(diff, n - diff));

            ans.push_back(minDist);
        }

        return ans;
    }
};