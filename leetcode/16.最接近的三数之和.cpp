/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int low, high;
        int result;
        int i;
        int temp, sum;
        result = nums[0]+nums[1]+nums[2];
        temp = nums[0]+nums[1]+nums[2] - target;
        temp = temp>0?temp:(-1*temp);
        for(i = 0;i<size-2;i++){
            low = i+1;
            high = size-1;
            while(low < high){
                sum = nums[i]+nums[low]+nums[high] - target;
                if(sum == 0){
                    return target;
                }
                int bias = sum>0?sum:(-1*sum);
                if(bias < temp){
                    temp = bias;
                    result = nums[i]+nums[low]+nums[high];
                }
                if(sum<0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

