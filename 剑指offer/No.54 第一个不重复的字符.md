# No.54 第一个不重复的字符

## 题目

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 

## 题解

一个map验证是否重复

一个vector按序插入，利用erase去重

```c++
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(data.count(ch) == 1){
            int l = sequence.size();
            for(int i =0; i<l; i++){
                if(sequence[i] == ch)
                    sequence.erase(sequence.begin()+i);
            }
        }
        else{
            data.insert(map<char, int>::value_type(ch,1));
            sequence.push_back(ch);
        }
        return;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(sequence.size()==0)
            return '#';
        return sequence[0];
    }
private:
    map<char, int> data;
    vector<char> sequence;
};
```

在已知类型为char的情况，用个bool数组就可以了，用不着map。。。。闹心