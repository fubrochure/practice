/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int l = nums.size();
        swap(0, l, nums, result);
        return result;
    }

    void swap( int n, int l, vector<int>& nums,vector<vector<int>>& result){
        int temp;
        if(n == l-1){
            result.push_back(nums);
            return;
        }
        for(int i = n; i < l;i++){
            temp = nums[n];
            nums[n] = nums[i];
            nums[i] = temp;
            swap(n+1,l,nums, result);
            temp = nums[n];
            nums[n] = nums[i];
            nums[i] = temp;
        }
    }
};
// @lc code=end

