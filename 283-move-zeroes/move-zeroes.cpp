class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =  nums.size();
        vector<int> arr(n);
        int pos = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                arr[pos]=nums[i];
                pos++;
            }
        }
            for(int i=pos;i<n;i++){
                arr[i]=0;
            }
            for(int i=0;i<n;i++){
                nums[i]=arr[i];
            }

        
        
    }
};