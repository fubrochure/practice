/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size()-1;
        int sum, flag;
        while(l>=0){
            sum = digits[l]+1;
            flag = sum/10;
            digits[l] = sum%10;
            if(flag == 0) break;
            //digits[l] = sum%10;
            l--;
        }
        if(flag){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
// @lc code=end

