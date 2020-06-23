# No.22 从上往下打印二叉树

## 题目

从上往下打印出二叉树的每个节点，同层节点从左至右打印。 

## 题解

二叉树的常见遍历方式队列

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> tree;
        if(root==NULL)
            return result;
        tree.push_back(root);
        for(int i= 0; i< tree.size();i++){
            result.push_back(tree[i]->val);
            if(tree[i]->left!=NULL)
                tree.push_back(tree[i]->left);
            if(tree[i]->right !=NULL){
                tree.push_back(tree[i]->right);
            }
        }
        return result;
    }
};
```

参考了别人的代码使用了队列，才想起来SLT确实有队列。。。难怪内存少用那么多

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> tree;
        if(root==NULL)
            return result;
        tree.push(root);
        while(!tree.empty()){
            TreeNode* temp = tree.front();
            tree.pop();
            result.push_back(temp->val);
            if(temp->left!=NULL)
                tree.push(temp->left);
            if(temp->right!=NULL)
                tree.push(temp->right);
            
        }
        return result;
    }
};
```

用了队列内存反而变多了？？？不懂。。。