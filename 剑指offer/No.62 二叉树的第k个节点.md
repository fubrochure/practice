# No.62 二叉树的第k个节点

## 题目

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。 

## 题解

递归中序遍历了一遍

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        vector<TreeNode*> result;
        if(k==0)
            return NULL;
        search(result, pRoot);
        if(k>result.size())
            return NULL;
        return result[k-1];
    }
private:
    void search(vector<TreeNode*>& result, TreeNode* root){
        if(root == NULL)
            return;
        search(result, root->left);
        result.push_back(root);
        search(result, root->right);
        return;
    }
    
};
```

花时间得想想中序遍历的非递归算法，似乎要用栈