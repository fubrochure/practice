# No.4 重建二叉树

## 题目

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。 

## 题解

啊这个边界条件以前总是要想半天，

前序遍历：根节点，左子树，右子树

中序遍历：左子树，根节点，右子树

通过前序遍历获取根节点在中序遍历上进行分割，之后递归。

递归要传递哪些数据一定要先想好。

```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int l = pre.size();
        if(l==0)
            return NULL;
        int pre_start = 0, pre_end = l-1;
        int vin_start = 0, vin_end = l-1;
        TreeNode* root = new TreeNode(pre[pre_start]);
        int index = vin_start;
        while(vin[index]!=pre[pre_start])
            index++;
        int left_len = index - vin_start;
        root->left = create_tree(pre, vin, pre_start+1, pre_start+left_len, vin_start, index-1);
        root->right = create_tree(pre, vin, pre_start+left_len+1, pre_end, index+1, vin_end);
        return root;
        
    }
    TreeNode* create_tree(vector<int>&pre, vector<int>&vin, int pre_start, int pre_end, int vin_start, int vin_end){
        if(pre_start>pre_end) 
            return NULL;
        TreeNode* root = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end)
            return root;
        int index = vin_start;
        while(vin[index]!=pre[pre_start])
            index++;
        int left_len = index - vin_start;
        root->left = create_tree(pre, vin, pre_start+1, pre_start+left_len, vin_start, index-1);
        root->right = create_tree(pre, vin, pre_start+left_len+1, pre_end, index+1, vin_end);
        return root;
    }
};
```

疯狂惨死。完全推翻重写时才发现是忘了子树为空的情况结果疯狂WA