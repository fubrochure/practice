# No.14 链表中倒数第k个节点

## 题目

输入一个链表，输出该链表中倒数第k个结点。 

## 题解

当时留下了深刻印象的双指针问题，就是各种神奇的边界条件让人捉不到头脑。

倒数超k原来返回NULL，倒数0也是返回NULL。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* tail = pListHead;
        if(pListHead == NULL)
            return NULL;
        if(k == 0){
            return NULL;
        }
        while(k>1 && tail->next!=NULL){
            tail = tail->next;
            k--;
        }
        if(k>1){
            return NULL;
        }
        while(tail->next!=NULL){
            tail= tail->next;
            pListHead = pListHead->next;
        }
        return pListHead;
        
    }
};
```

