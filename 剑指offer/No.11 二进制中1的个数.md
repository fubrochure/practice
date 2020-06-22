# No.11二进制中1的个数

## 题目

提供一个int判断其二进制中有多少个1

## 题解

位运算移位，但是注意如果是负数，首先判断符号位之后需要把最高位置0，否则右移会补1。

也不建议直接乘-1变成正数，毕竟负数取值范围大1，小心溢出。

```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int result = 0;
         if(n<0){
             result++;
             n &= 0x7fffffff;
         }
         while(n!=0){
             if (n & 0x01 == 1)
                 result++;
             n>>=1;
         }
         return result;
     }
};
```

