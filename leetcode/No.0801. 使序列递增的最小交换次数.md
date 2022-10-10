# [801. 使序列递增的最小交换次数](https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/)

## 题目

我们有两个长度相等且不为空的整型数组 nums1 和 nums2 。在一次操作中，我们可以交换 nums1[i] 和 nums2[i]的元素。

例如，如果 nums1 = [1,2,3,8] ， nums2 =[5,6,7,4] ，你可以交换 i = 3 处的元素，得到 nums1 =[1,2,3,4] 和 nums2 =[5,6,7,8] 。
返回 使 nums1 和 nums2 严格递增 所需操作的最小次数 。

数组 arr 严格递增 且  arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1] 。

注意：

用例保证可以实现操作。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 思路

用例保证可以实现，每次看相邻的两组之间的关系就行。

动归，二维dp数组。

dp\[0\]\[i\]记录不反转第i对需要的最小翻转数，dp\[1\]\[i\]记录翻转第i对需要的最小翻转数。

取值依赖与之前的一组的数据。根据这一组和前一组的是否翻转以及是否合法取最小值。

```c++
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        //row 0: not switch; row1: switch
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[1][0] = 1;
        for(int i=1;i<n;i++){
            int r0 = INT_MAX, r1 = INT_MAX; 
            if(nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]){
                r0 = min(r0, dp[0][i-1]);
                r1 = min(r1, dp[1][i-1]+1);
            }
            if(nums1[i-1]< nums2[i] && nums2[i-1]< nums1[i]){
                r0 = min(r0, dp[1][i-1]);
                r1 = min(r1, dp[0][i-1]+1);
            }
            dp[0][i] = r0;
            dp[1][i] = r1;
            // cout<< r0<<" "<< r1<<endl;
        }
        return min(dp[0][n-1], dp[1][n-1]);
    }
};
```



