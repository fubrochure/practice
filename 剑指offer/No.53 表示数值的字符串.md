# No.53 表示数值的字符串

## 题目

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。 

## 题解

代码没什么需要特别注意的地方，主要是思路，哪些情况是符合情况的字符串，以下条件顺着判断一遍：

- 初始有（无）正负号
- 处理数字
- 处理小数点（注意，这部分小数点前没有数字也可以
- 处理数字
- 处理指数符号
- 处理指数正负号
- 处理指数（这部分至少要有一个数字

之后判断是否到字符串末尾即可

```c++
class Solution {
public:
    bool isNumeric(char* string)
    {
        int index = 0;
        if(string[index] == '-' || string[index]=='+')
            index++;
        while(string[index]>='0' && string[index]<='9')
            index++;
        if(string[index]=='.'){
            index++;
            if(string[index]<'0' || string[index]>'9')
                return false;
            while(string[index]>='0' && string[index]<='9')
                index++;
        }
        if(string[index] == 'e' || string[index]== 'E'){
            index++;
            if(string[index] == '-' || string[index]=='+')
                index++;
            if(string[index]<'0' || string[index]>'9')
                return false;
            while(string[index]>='0' && string[index]<='9')
                index++;
        }
        if(string[index]!=0)
            return false;
        else
            return true;
    }

};
```

