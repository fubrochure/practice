# No.17 树的子结构

## 题目

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构） 

## 题解

遍历树的每一个节点与B树进行比较

当A树子节点没遍历完但是B树节点遍历完时也是子结构。因此WA了一次。

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL)
            return false;
        if(pRoot2==NULL)
            return false;
        vector<TreeNode*> nodes;
        nodes.push_back(pRoot1);
        for(int i=0; i< nodes.size();i++){
            if(nodes[i]->left!=NULL)
                nodes.push_back(nodes[i]->left);
            if(nodes[i]->right!=NULL){
                nodes.push_back(nodes[i]->right);
            }
            if(compare(nodes[i], pRoot2))
                return true;
        }
        return false;
        
    }
    
    bool compare(TreeNode* t1, TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return true;
        if(t1==NULL)
            return false;
        if(t2==NULL)
            return true;
        return (t1->val == t2->val)&& compare(t1->left, t2->left) && compare(t1->right, t2->right);
        
    }
    
};
```

