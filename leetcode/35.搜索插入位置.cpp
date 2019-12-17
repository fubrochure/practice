/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if(high < 0){
            return 0;
        }
        int mid;
        //int mid = (low + high)/2;
        while(low < high){
            mid = (low + high) /2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(nums[low]<target){
            return low+1;
        }
        else{
            return low;
        }
        

    }
};
// @lc code=end

