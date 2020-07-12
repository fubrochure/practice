# No.174 Dungeon Game

## 题面

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dungeon-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 题解

要求的是起初的最小体力，中途为0直接结束，所以从开始进行深搜不可能。假设从右下最后剩1点体力向上开始搜索。

搜索时发现每个点（非边缘）都是两个位置选一（下面或者右方）不用广搜直接dp就完了。

因为过程中体力不能为0，所以逆向时减去恢复若小于零需要置为1。

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        if(rows<1)
            return -1;
        int cols = dungeon[0].size();
        if(cols<1)
            return -1;
        vector<vector<int>> dp(rows, vector<int>(cols,1));
        for(int i = rows-1; i>=0; i--){
            for(int j = cols-1 ;j>=0;j--){
                if(i == rows-1 && j == cols-1){
                    dp[i][j] = max(1-dungeon[i][j], 1);
                }
                else if(i == rows- 1){
                    dp[i][j] = max(dp[i][j+1]-dungeon[i][j],1);
                }
                else if(j == cols-1){
                    dp[i][j] = max(dp[i+1][j]-dungeon[i][j], 1);
                }
                else{
                    int down = max(dp[i+1][j]-dungeon[i][j], 1);
                    int right = max(dp[i][j+1]-dungeon[i][j],1);
                    dp[i][j] = min(down, right);
                }
                
            }
        }
        return dp[0][0];
    }

};
```

上帝呀竟然一遍过了

