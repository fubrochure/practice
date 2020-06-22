# No.3 从尾到头打印链表

## 题目

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。 

## 解题

没发现什么特别需要注意的知识点，只要数据结构学好就没啥问题了。

STL真好啊真好啊，insert 是什么神仙方法。

```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> results;
        while(head!=NULL){
            results.insert(results.begin(), head->val);
            head = head->next;
        }
        return results;
    }
};
```

