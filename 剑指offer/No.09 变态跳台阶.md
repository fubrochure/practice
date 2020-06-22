# No.9 变态跳台阶

## 题目

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。 

## 题解

每一个相当于1+之前的所有的结果
$$
a_{n-1} = 1+a_{n-2}+ \cdots + a_{1}
$$

$$
a_{n} = 1 + a_{n-1} + \cdots + a_{1}
$$

可得
$$
a_{n} = 2*a_{n-1}
$$

```c++
class Solution {
public:
    int jumpFloorII(int number) {
        int* result = new int[number+1];
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
        for(int i=3;i<=number;i++){
            result[i] = 2*result[i-1];
        }
        return result[number];
    }
};
```

