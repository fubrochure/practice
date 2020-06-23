# No.21 栈的压入顺序

## 题目

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的） 

## 题解

模拟一次压入

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int p1 = pushV.size();
        int p2 = 0;
        stack<int> data;
        for(int i=0;i<p1;i++){
            data.push(pushV[i]);
            while(!data.empty()){
                if(data.top() == popV[p2]){
                    data.pop();
                    p2++;
                }
                else{
                    break;
                }
            }
        }
        if(data.empty())
            return true;
        return false;
    }
};
```

