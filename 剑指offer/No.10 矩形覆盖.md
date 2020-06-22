# No.10 矩形覆盖

## 题目

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 

## 题解

感觉和跳台阶类似

当多出一格时，竖着填充进去一种方法

当多出两格时， 竖着填充两个和之前冲突，横着填充两个可行

多出三格或者以上，是进行填充时是一格或者两格的子集。

```c++
class Solution {
public:
    int rectCover(int number) {
        int* result = new int[number+1];
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
        for(int i=3; i<=number; i++){
            result[i] = result[i-1]+ result[i-2];
        }
        return result[number];
    }
};
```

