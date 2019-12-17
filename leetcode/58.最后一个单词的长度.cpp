/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length()-1;
        if(l < 0){
            return 0;
        }
        int result = 0;
        while(s[l]==' '){
            l--;
        }
        if(l<0){
            return 0;
        }
        while(l>=0){
            if(s[l]!=' '){
                result++;
            }
            else{
                break;
            }
            l--;
        }
        return result;

    }
};
// @lc code=end

