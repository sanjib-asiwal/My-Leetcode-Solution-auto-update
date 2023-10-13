class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum=0,ans=INT_MAX;
        int l=0;
        for(int r=0;r<nums.size();r++){
            curr_sum+=nums[r];
            
            while(curr_sum>=target){
                ans=min(ans,r-l+1);
                curr_sum-=nums[l];
                l++;
                
            }
        }
        if(ans==INT_MAX) return 0;
            return ans;
    }
};