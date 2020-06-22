# No.7  斐波那契数列

## 题目

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。

n<=39

## 解题

```c++
class Solution {
public:
    int Fibonacci(int n) {
        int* results = new int[n+1];
        results[0] = 0;
        results[1] = 1;
        for(int i = 2; i<=n; i++){
            results[i] = results[i-2]+results[i-1];
        }
        return results[n];
    }
};
```

