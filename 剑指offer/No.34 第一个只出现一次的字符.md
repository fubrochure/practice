# No.34 第一个只出现一次的字符

## 题目

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数） 

## 题解

```c++
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int l = str.length();
        int a[60];
        memset(a, 0, sizeof(int)*60);
        for(int i=0;i<l;i++){
            a[str[i]-'A'] ++;
        }
        for(int i=0;i<l;i++){
            if(a[str[i]-'A'] == 1)
                return i;
        }
        return -1;
    }
};
```

利用了每个字符的数据作为下标维持了数组记录出现的次数

利用希望标记的数据的值作为下标进行寻址这个操作见过好多次了，以后得记着点。