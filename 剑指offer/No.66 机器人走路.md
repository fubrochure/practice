# No.66 机器人走路

## 题目

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？ 

## 题解

因为需要从0，0 开始走，做标记广搜即可

```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> data(rows, vector<bool>(cols, true));
        queue<Position*> sequence;
        int result;
        if(rows<1 || cols<1 || threshold<0){
            return 0;
        }
        sequence.push(new Position(0,0));
        data[0][0]=false;
        Position* temp;
        while(!sequence.empty()){
            temp = sequence.front();
            sequence.pop();
            result++;
            if(check(data, temp->row-1, temp->col, rows, cols, threshold)){
                sequence.push(new Position(temp->row-1, temp->col));
                data[temp->row-1][temp->col] = false;
            }
            if(check(data, temp->row+1, temp->col, rows, cols, threshold)){
                sequence.push(new Position(temp->row+1, temp->col));
                data[temp->row+1][temp->col] = false;
            }
            if(check(data, temp->row, temp->col-1, rows, cols, threshold)){
                sequence.push(new Position(temp->row, temp->col-1));
                data[temp->row][temp->col-1] = false;
            }
            if(check(data, temp->row, temp->col+1, rows, cols, threshold)){
                sequence.push(new Position(temp->row, temp->col+1));
                data[temp->row][temp->col+1] = false;
            }
            free(temp);
        }
        return result;
    }
private:
    struct Position{
        int row;
        int col;
        Position(int a, int b):row(a),col(b){}
    };
    
    bool check(vector<vector<bool>>& data, int x, int y, int rows, int cols, int threshold){
        if(x<0||x>rows-1 || y<0 || y> cols-1)
            return false;
        int sum = 0;
        int row = x, col = y;
        while(row!=0){
            sum+=row%10;
            row/=10;
        }
        while(col!=0){
            sum+=col%10;
            col/=10;
        }
        if(sum>threshold)
            return false;
        return data[x][y];
    }
};
```

