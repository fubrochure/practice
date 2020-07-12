# No.49 字符串转化为整数

## 题目

将字符串转化为整数

## 题解

```c++
class Solution {
public:
    int StrToInt(string str) {
        int l = str.length();
        if(l == 0)
            return 0;
        int flag = 1;
        int i = 0;
        if(str[i] == '-'){
            flag = 0;
            i++;
        }
        if(str[i] == '+'){
            i++;
        }
        int result = 0;
        for(; i< l;i++){
            if(str[i]<'0' || str[i] >'9')
                break;
            result*=10;
            result+=str[i]-'0';
        }
        if(i!=l)
            return 0;
        if(flag == 1)
            return (int)result;
        else
            return -1*(int)result;
    }
};
```

