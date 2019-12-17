/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        int l = nums.size();
        int i = 0;
        while(i<l){
            sum += nums[i];
            max = sum>max?sum:max;
            if(sum<0){
                sum = 0;
            }
            i++;
        }
        return max;
    }
};
// @lc code=end

