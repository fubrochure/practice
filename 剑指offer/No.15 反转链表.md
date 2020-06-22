# No.15 反转链表

## 题目

输入一个链表，反转链表后，输出新链表的表头。 

## 题解

之前没做出来就一直空着，没想到这次顺利的过了。

需要三个指针，tail下一个（下一个更改指针的节点），now当前（当前更改指针的节点），head末尾（被链接的节点）。

每次tail不为空时更新now前移，之后更新tail。将now的指针修改为head，head指向now。

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        if(pHead->next==NULL){
            return pHead;
        }
        ListNode* now = pHead;
        ListNode* head = pHead;
        ListNode* tail = now->next;
        while(tail!=NULL){
            now = tail;
            tail = now->next;
            now->next =head;
            head = now;
        }
        pHead->next=NULL;
        return now;
    }
};
```

注意最后返回的是now，tail跳出循环时为空了。最后更新的节点（最后一个）是now。