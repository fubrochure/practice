# No.58 对称二叉树

## 题目

请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。 

## 题解

边界条件，空树先判断一波。

之后对于两个子节点，值必须相等，其左节点左子树的与右节点右子树，左节点右子树和右节点左子树必须对称。

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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        if(pRoot->left==NULL && pRoot->right==NULL)
            return true;
        return check(pRoot->left, pRoot->right);
    }
    
    bool check(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        if(left==NULL || right==NULL)
            return false;
        if(left->val!=right->val)
            return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
};
```

