/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int i,j;
        int temp;
        int x = board.size();
        int y = board[0].size();
        for(i = 0; i < x; i++){
            for(j = 0; j < y; j++){
                temp = 0;
                if(i>0 && j>0){
                    temp += board[i-1][j-1] & 1; 
                }
                if(i>0 && j<y-1){
                    temp += board[i-1][j+1] & 1;
                }
                if(i<x-1 && j>0){
                    temp+= board[i+1][j-1] & 1;
                }
                if(i<x-1 && j<y-1){
                    temp+= board[i+1][j+1] & 1;
                }
                if(i>0){
                    temp+= board[i-1][j] & 1;
                }
                if(i<x-1){
                    temp+= board[i+1][j] & 1;
                }
                if(j>0){
                    temp+= board[i][j-1] & 1;
                }
                if(j<y-1){
                    temp+= board[i][j+1] & 1;
                }
                //std::cout<<" "<<temp;
                if(temp < 2){
                    board[i][j] &= 1;
                }
                if(temp == 2  && board[i][j] == 1){
                    board[i][j] |= 2;
                }
                if(temp>3){
                    board[i][j] &= 1;
                }
                if(temp == 3){
                    board[i][j] |= 2;
                }

            }
            //std::cout<<endl;
        }
        for(i = 0; i < x;i++){
            for(j = 0; j < y;j++){
                board[i][j]>>= 1;
            }
        }

    }
};
// @lc code=end

