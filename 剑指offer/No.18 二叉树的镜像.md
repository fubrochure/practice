# No.18 二叉树的镜像

## 题目

操作给定的二叉树，将其变换为源二叉树的镜像。 

## 题解

记得判断根节点，递归。

```c++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot ==NULL)
            return;
        change(pRoot);
        return;
    }
    
    void change(TreeNode* root){
        if(root->left==NULL && root->right==NULL)
            return;
        if(root->left!=NULL)
            change(root->left);
        if(root->right!=NULL)
            change(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return;
    }
};
```

