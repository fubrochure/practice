# No.25 复杂链表的复制

## 问题

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空） 

## 题解

先将链表顺序复制，利用map记录旧node到新node的地址映射。

再遍历新链表一次，本次对于random指针进行更新。注意random为NULL的情况。

```c++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        map<RandomListNode*, RandomListNode*> dict;
        RandomListNode* p_tail = pHead;
        RandomListNode* q_head  = new RandomListNode(pHead->label);
        q_head->random = pHead->random;
        dict.insert(map<RandomListNode*, RandomListNode*>::value_type(pHead, q_head));
        RandomListNode* q_tail = q_head;
        while(p_tail->next != NULL){
            p_tail = p_tail->next;
            RandomListNode* node = new RandomListNode(p_tail->label);
            dict.insert(map<RandomListNode*, RandomListNode*>::value_type(p_tail, node));
            node->random = p_tail->random;
            q_tail->next = node;
            q_tail = q_tail->next;
        }
        q_tail = q_head;
        while(q_tail!=NULL){
            if(q_tail->random == NULL){
                q_tail = q_tail->next;
                continue;
            }
            map<RandomListNode*, RandomListNode*>::iterator it;
            it = dict.find(q_tail->random);
            if(it==dict.end()){
                RandomListNode* node = new RandomListNode(q_tail->random->label);
                dict.insert(map<RandomListNode*, RandomListNode*>::value_type(q_tail->random, node));
            }
            q_tail->random = dict[q_tail->random];
            q_tail = q_tail->next;
        }
        return q_head;
    }
};
```

