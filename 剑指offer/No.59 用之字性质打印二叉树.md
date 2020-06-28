# No.59 用之字性质打印二叉树

## 题目

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。 

## 题解

新建一个结构体，记录节点和节点再完全二叉树中应该具备的编号

根据编号判断行，确定插入顺序

vector::insert永远滴神

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
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot==NULL)
            return result;
        queue<OrderedNode*> sequence;
        sequence.push(new OrderedNode(pRoot, 1));
        OrderedNode* temp;
        int row;
        while(!sequence.empty()){
            temp = sequence.front();
            sequence.pop();
            if(temp->node->left!=NULL)
                sequence.push(new OrderedNode(temp->node->left, temp->num *2));
            if(temp->node->right!=NULL)
                sequence.push(new OrderedNode(temp->node->right, temp->num*2+1));
            row = get_row(temp->num);
            if(result.size()<row+1){
                vector<int> a;
                result.push_back(a);
            }
            if(row%2==0)
                result[row].push_back(temp->node->val);
            else
                result[row].insert(result[row].begin(), temp->node->val);
        }
        return result;
    }
private:
    struct OrderedNode{
        TreeNode* node;
        int num;
        OrderedNode(TreeNode* temp, int x):
            node(temp),num(x){}
    };
    
    int get_row(int n){
        int row = -1;
        while(n!=0){
            row++;
            n/=2;
        }
        return row;
    }
};
```

题解用了两个栈，交替进行。说明完全其实不需要具体计算其是第几行，只需依行，不断出栈即可。。。牛的