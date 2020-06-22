# No.5 用两个栈实现队列

## 题目

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。 

## 解题

数据经过两次压栈之后出栈顺序就变为先入先出，但第二个栈非空时不能压入数据。即一段一段的保持先进先出。

```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

