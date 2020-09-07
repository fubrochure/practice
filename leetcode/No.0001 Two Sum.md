# No.1 Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

给定一个数组，求取其中两个数的位置，使两个数之和为指定值

初步设想是排序后双指针

阅读题解之后发现使用hashmap，以 target-num[i] 作为key保存num[i]的位置，当map中find发现时即发现了解。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(index.find(nums[i])!=index.end()){
                result.push_back(index[nums[i]]);
                result.push_back(i);
                break;
            }
            else{
                index[target-nums[i]] = i;
            }
        }
        return result;
    }
};
```

