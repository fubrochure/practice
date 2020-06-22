# No.8 跳台阶

## 题目

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。 

## 题解

和斐波那契一个东西

```c++
class Solution {
public:
    int jumpFloor(int number) {
        int* result = new int[number+1];
        result[1] = 1;
        result[2] = 2;
        for(int i=3; i<=number; i++){
            result[i] = result[i-1]+result[i-2];
        }
        return result[number];
    }
};
```

