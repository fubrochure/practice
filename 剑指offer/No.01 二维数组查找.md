# No.1 二维数组查找

## 题目

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 

## 解题

如果从左上或者右下开始，向右和向下（向左和向上）数据都是同样的变化方向，BFS有重复而且猜测会爆吧。。。

从左下或者右上开始，虽然有些难理解但是画个图还是能够明白每次移动舍弃的都是绝对不符合条件的数据。

```C++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if (row == 0) 
            return false;
        int col = array[0].size();
        if (col == 0)
            return false;
        int i = 0, j = col -1;
        while(i >= 0 && i < row && j>=0 && j < col){
            if (array[i][j]>target)
                j--;
            else if(array[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};
```

第一版代码，循环条件多了，明明每一个都只有一个移动方向。。。