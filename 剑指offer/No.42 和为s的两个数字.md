# No.42 和为s的两个数字

## 题目

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 

## 题解

双指针，参考leetcode的两个数之和最接近那个

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int head = 0, tail = array.size()-1;
        vector<int> result;
        while(head<tail){
            if(array[head]+array[tail]>sum)
                tail--;
            else if(array[head]+array[tail]<sum)
                head++;
            else{
                result.push_back(array[head]);
                result.push_back(array[tail]);
                break;
            }
        }
        return result;
    }
};
```

