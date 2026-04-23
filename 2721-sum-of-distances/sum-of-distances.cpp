class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;
        
        // Store indices of same values
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();
            
            vector<long long> prefix(m + 1, 0);
            
            // Prefix sum of indices
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }
            
            for (int i = 0; i < m; i++) {
                long long left = 1LL * i * v[i] - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - 1LL * (m - i - 1) * v[i];
                ans[v[i]] = left + right;
            }
        }
        
        return ans;
    }
};