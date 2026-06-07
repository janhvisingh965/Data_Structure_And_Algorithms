class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int w = right-left;
            int ht = min(height[left],height[right]);
            int water = w * ht;
            ans = max(ans,water);
            height[left]<height[right]?left++:right--;
        }
        return ans;
        
    }
};