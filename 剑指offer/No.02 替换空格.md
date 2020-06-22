# No.2 替换空格

## 题目

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 

## 解题

替换就完事了，但是一开始没仔细没看函数是void，还开心的新new了一个char数组。。。这部分需要反省

在扩容的时候，为了避免每次空格替换都对之后的数据进行移动，从末尾开始。所以记得计算末尾的坐标。

末尾还是想起来后还是补了个字符串结束标识，许久没用C++还好这个没忘。（不知道不加过不过得掉

```c++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(length == 0)
            return;
        int count = 0;
        for(int i = 0; i< length-1; i++){
            if(str[i] == ' ')
                count++;
        }
        int n_length  = length + 2*count;
        int old_tail = length -1, new_tail = length+2*count -1; 
        str[new_tail] = 0;
        while(old_tail>=0){
            if(str[old_tail]!=' ')
                str[new_tail] = str[old_tail];
            else{
                str[new_tail--] = '0';
                str[new_tail--] = '2';
                str[new_tail] = '%';
            }
            old_tail--;
            new_tail--;
        }
	}
};
```

最近是认真刷题，变量名之类地还是得认真起了。