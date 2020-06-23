# No.19 顺时针打印矩阵

## 题目



## 题解

就确定上下左右的范围，在其中按照右，下，左上的方式移动即可

判断是每次到达一个边界就要判断,原来写成一个大循环才判断了。。。

```c++
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int high = matrix.size()-1;
        if(high<0)
            return result;
        int right = matrix[0].size()-1;
        if(right<0)
            return result;
        int x = 0, y = 0, low = 0, left = 0;
        while(x>= left && x<= right && y>=low && y<= high){
            while(x<=right){
                result.push_back(matrix[y][x++]);
            }
            x--;
            y++;
            low++;
            if(left> right || low >high)
                break;
            while(y<=high){
                result.push_back(matrix[y++][x]);
            }
            y--;
            x--;
            right--;
            if(left> right || low >high)
                break;
            while(x>=left){
                result.push_back(matrix[y][x--]);
            }
            x++;
            y--;
            high--;
            if(left> right || low >high)
                break;
            while(y>=low){
                result.push_back(matrix[y--][x]);
            }
            y++;
            x++;
            left++;
            if(left> right || low >high)
                break;
        }
        return result;
    }
};
```

