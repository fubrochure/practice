# No.60 把二叉树打印成多行

## 题目

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。 

## 题解

上一题的变体，题解换成队列就行了,插入vector时记得判空

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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> result;
            if(pRoot==NULL)
                return result;
            queue<TreeNode*> q1, q2;
            q1.push(pRoot);
            TreeNode* temp;
            while(!q1.empty()){
                vector<int> v1, v2;
                while(!q1.empty()){
                    temp = q1.front();
                    q1.pop();
                    if(temp->left!=NULL)
                        q2.push(temp->left);
                    if(temp->right!=NULL)
                        q2.push(temp->right);
                    v1.push_back(temp->val);
                }
                while(!q2.empty()){
                    temp = q2.front();
                    q2.pop();
                    if(temp->left!=NULL)
                        q1.push(temp->left);
                    if(temp->right!=NULL)
                        q1.push(temp->right);
                    v2.push_back(temp->val);
                }
                if(v1.size()>0)
                    result.push_back(v1);
                if(v2.size()>0)
                    result.push_back(v2);
            }
            return result;
        }
    
};
```

