/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int a[INT_MAX] = {0};
    int leastBricks(vector<vector<int>>& wall) {
        
        int row = wall.size();
        int col;
        int i,j,k;
        int sum = 0;
        for(i = 0; i< row;i++){
            col = wall[i].size();
            sum = 0;
            for(j = 0;j< col;j++){
                sum+=wall[i][j];
                a[sum]++;
            }

        }
        int min = 20000;
        for(i = 1;i<INT_MAX;i++){
            min = a[i]<min?a[i]:min;
        }
        return min;
    }
};
// @lc code=end

