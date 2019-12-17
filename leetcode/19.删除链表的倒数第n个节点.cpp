/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> container;
        ListNode* p = head;
        while(p!= NULL){
            container.push_back(p);
            p = p->next;
        }
        int size = container.size();
        int target = size - n;
        if(target == 0){
            return head->next;
        }
        container[target-1]->next = container[target]->next;
        return head;
    }
};
// @lc code=end

