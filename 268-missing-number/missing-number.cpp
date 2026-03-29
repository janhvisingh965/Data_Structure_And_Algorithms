class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> check(n+1,false);
            for(int i=0;i<n;i++){
                int x= nums[i];
                check[x]=true;
            }
             for(int i=0;i<=n;i++){
                if(check[i]==false){
                    return i;
                }
             

        }
        return 100;
        
    }
};