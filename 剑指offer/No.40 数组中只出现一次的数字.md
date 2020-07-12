# No.40 数组中只出现一次的数字

## 题目

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。 

## 题解

用map直接处理了

```c++
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> count;
        vector<int>::iterator it;
        for(it = data.begin();it!=data.end();it++){
            if(count.find(*it) !=count.end())
                count[*it] +=1;
            else
                count.insert(map<int, int>::value_type(*it,1));
        }
        vector<int> result;
        for(map<int, int>::iterator it = count.begin();it!= count.end();it++){
            if(it->second > 1)
                continue;
            result.push_back(it->first);
        }
        *num1 = result[0];
        *num2 = result[1];
        return;
    }
};
```

题解里出现了一个用异或的方法

```c++
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int l = data.size();
        if(l==0)
            return;
        int flag = 0;
        for(int i = 0;i<l;i++){
            flag ^= data[i];
        }
        int index = 1;
        while((flag & index)==0){
            index<<=1;
        }
        *num1 = 0;
        *num2 = 0;
        for(int i=0;i<l;i++){
            if((data[i]&index)!=0) //没加括号WA了两次。。。。
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
        return;
    }
};
```

没加括号WA了两次，但是这个运算级怎么会出问题，想不通。。。

