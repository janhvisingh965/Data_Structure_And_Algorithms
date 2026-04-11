class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            auto &v = it.second;
            int sz = v.size();

            if (sz < 3) continue;

            // Check consecutive triples
            for (int i = 0; i + 2 < sz; i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};