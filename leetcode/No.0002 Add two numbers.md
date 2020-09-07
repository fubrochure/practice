# No.2 Add two numbers

## Question

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Answer

直接贴代码

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *result = l1;
        int flag = 0;
        while(true){
            l1->val = l1->val + l2->val + flag;
            flag = l1->val/10;
            l1->val %=10;
            if(l1->next ==NULL || l2->next==NULL)
                break;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1->next == NULL)
            l1->next = l2->next;
        while(l1->next!=NULL){
            l1=l1->next;
            l1->val = l1->val + flag;
            flag = l1->val/10;
            l1->val %=10;
        }
        if(flag == 1)
            l1->next =new ListNode(1);
        return result;
    }
};
```

为了省空间，写错了好多次orz

不省空间的标准写法附上

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        int carry = 0, sum;
        while(l1!=NULL && l2!=NULL){
            sum = l1->val+l2->val+carry;
            tail->next = new ListNode(sum%10);
            carry = sum/10;
            l1=l1->next;
            l2=l2->next;
            tail=tail->next;
        }
        if(l1==NULL)
            l1 = l2;
        while(l1!=NULL){
            int sum = l1->val+carry;
            tail->next = new ListNode(sum%10);
            carry = sum/10;
            l1=l1->next;
            tail = tail->next;
        }
        if(carry==1){
            tail->next = new ListNode(carry);
        }
        return head->next;
    }
};
```

这个为什么时间比上一个少呢= =，不会真的是l1->val赋值浪费的时间吧。。。