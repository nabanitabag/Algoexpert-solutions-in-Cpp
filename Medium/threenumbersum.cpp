/* Leetcode medium (3sum)
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []


Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105 */

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < nums.size() ; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
        while(l<r){
            int s = nums[i] + nums[l] + nums[r];
            if (s < 0)
                l++;
            else if(s > 0)
                r--;
            else{
                ans.push_back({nums[i], nums[l], nums[r]});
                //handle duplication here
                while (l < r && nums[l]==nums[l+1]) l++;
                while (l < r && nums[r]==nums[r-1]) r--;
                l++;
                r--;
            }
        }
    }
    return ans;
}
