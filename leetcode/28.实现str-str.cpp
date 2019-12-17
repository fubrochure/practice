/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        int l = needle.length();
        int i, j;
        for(i = 0; i + l <= haystack.length();i++){
            j = 0;
            while(j<l){
                if(haystack[i+j]!=needle[j]) break;
                j++;
            }
            if(j==l) return i;
        }
        return -1;
    }
};
// @lc code=end

