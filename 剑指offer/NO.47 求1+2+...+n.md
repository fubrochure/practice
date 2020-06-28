# NO.47 求1+2+...+n

## 题目

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。 

## 题解

用递归来替代循环

```c++
class Solution {
public:
    int Sum_Solution(int n) {
        return multiple(n+1, n)>>1;
    }
    
    int multiple(int a, int b){
        if(b == 0)
            return 0;
        if(b&0x01 == 1)
            return a + multiple(a<<1, b>>1);
        else
            return multiple(a<<1, b>>1);
    }
};
```

