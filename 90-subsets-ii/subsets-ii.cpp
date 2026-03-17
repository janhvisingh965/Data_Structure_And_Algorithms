class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalans, int idx, bool flag) {
        if (idx == nums.size()) {
            finalans.push_back(ans);
            return;
        }

        
        helper(nums, ans, finalans, idx + 1, false);

       
        if (idx > 0 && nums[idx] == nums[idx - 1] && flag == false) {
            return;
        }

        
        ans.push_back(nums[idx]);
        helper(nums, ans, finalans, idx + 1, true);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        vector<int> ans;
        vector<vector<int>> finalans;

        helper(nums, ans, finalans, 0, true);
        return finalans;
    }
};