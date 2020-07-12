# No.33 丑数

## 题目

把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。 

## 题解

这题完全参考了样例代码。。。

```c++
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> result(index+1,1);
        int index2 = 0, index3= 0, index5 = 0;
        for(int i=1;i<index;i++){
            result[i] = min(result[index2]*2, min(result[index3]*3, result[index5]*5));
            if(result[i] == result[index2]*2)
                index2++;
            if(result[i] == result[index3]*3)
                index3++;
            if(result[i] == result[index5]*5)
                index5++;
        }
        return result[index-1];
    }
};
```



相当于为2，3，5分别维持了一个队列，选出最小数之后乘以2，3，5放入相应的队列中，因为选数字进去，所以队列内部保持严格的升序，只需比较队列头即可