# No.16 合并两个排序链表

## 题目

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。 

## 题解

首先判断不为空。

再处理在头节点前插入的情况。

再处理在头节点之外的位置插入的情况。

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL){
            return pHead2;
        }
        if(pHead2 == NULL)
            return pHead1;
        while(pHead2!=NULL){
            if(pHead2->val > pHead1->val)
                break;
            ListNode* temp = pHead2;
            pHead2= pHead2->next;
            temp->next = pHead1;
            pHead1 = temp;
        }
        ListNode* p_inserted = pHead1;
        ListNode* p_insert = pHead2;
        while(p_inserted->next !=NULL && p_insert != NULL){
            if(p_inserted->next->val >= p_insert->val){
                ListNode* temp = p_insert;
                p_insert = p_insert->next;
                temp->next = p_inserted->next;
                p_inserted->next = temp;
            }
            else{
                p_inserted = p_inserted->next;
            }
        }
        if(p_insert!=NULL){
            p_inserted->next = p_insert;
        }
        return pHead1;
    }
};
```

