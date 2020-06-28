# No.48 不用加减乘除做加法

## 题目

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。 

## 题解

```c++
class Solution {
public:
    int Add(int num1, int num2)
    {
        int temp;
        while(num2!=0){
            temp = num1 ^ num2;
            num2 = (num1 & num2)<<1;
            num1 = temp;
        }
        return num1;
    }
};
```

