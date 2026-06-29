class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        int ans = 0;

        // Count subarrays where target is the majority
        // i.e. (#target) > (#non-target)
        // => transformed sum > 0
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (prefix[j] > prefix[i])
                    ans++;
            }
        }

        return ans;
    }
};