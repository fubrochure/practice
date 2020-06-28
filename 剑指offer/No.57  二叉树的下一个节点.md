# No.57  二叉树的下一个节点

## 题目

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。 

## 题解

如果右子树不为空，对右子树进行中序遍历

如果右子树为空，递归判断其是不是父节点的左节点，是返回父节点，不是继续向上

```
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode->right!=NULL)
            return inorder(pNode->right);
        return next(pNode);
    }
    
    TreeLinkNode* inorder(TreeLinkNode* root){
        while(root->left!=NULL){
            root= root->left;
        }
        return root;
    }
    
    TreeLinkNode* next(TreeLinkNode* root){
        TreeLinkNode* father = root->next;
        if(father == NULL)
            return NULL;
        if(root == father->left)
            return father;
        return next(father);
    }
};
```

