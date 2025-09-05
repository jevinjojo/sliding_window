class Solution {
public:
// sub array 
// 
// Subarrays with sum <= k include those with sum exactly k and those with sum < k.
// Subarrays with sum <= k-1 are exactly those with sum < k.
    int countSubarrays(vector<int>& nums, int goal){
        if(goal<0)  return 0;

        // Time complexity can be increased a lot..
            // so convientet.
        int l=0,r=0,count=0,sum=0;
        int n = nums.size();

        while(r < n){

            sum += nums[r];
            
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarrays(nums,goal) - countSubarrays(nums,goal-1);
    }
};
