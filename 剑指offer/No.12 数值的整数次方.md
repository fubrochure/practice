# No.12 数值的整数次方

## 题目

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0

## 题解

看完题目自以为题目把坑填了，事实上还有个坑是负数。。。

```c++
class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)
            return 0;
        if(exponent == 0)
            return 1;
        double result = 1;
        if(exponent>0)
            for(int i = 0;i<exponent; i++){
                result *= base;
            }
        else
            for(int i = 0;i >exponent; i--){
                result /= base;
            }
        return result;
    }
};
```

