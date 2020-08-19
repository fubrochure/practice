# No.1552 两球之间的磁力

在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。

已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。

给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。

输入：position = [1,2,3,4,7], m = 3
输出：3
解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。

输入：position = [5,4,3,2,1,1000000000], m = 2
输出：999999999
解释：我们使用位于 1 和 1000000000 的篮子时最小磁力最大。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magnetic-force-between-two-balls
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

202周赛第三题

当时完全没做出来。。。不知道脑子里装着什么

看了解题的二分发现并不是很难的思路，不如说二分因为一直没有什么惊为天人的操作所以一直会被忘记。

磁力最小是相邻篮子的最小间距，最大是整个距离均分（最理想）。

根据这个最大最小值进行二分一个一个去试

```c++
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int min=INT_MAX, max = position.back() - position.front();
        int l = position.size();
        for(int i=1; i< l;i++){
            min = min<(position[i]-position[i-1])?min:(position[i]-position[i-1]);
        }
        if(m==l){
            return min;
        }
        max/=m-1;
        while(min<max-1){
            int mid = (max+min)/2;
            if(check(position, m, mid)){
                min = mid;
            }
            else{
                max = mid-1;
            }
        }
        if(check(position, m, max))
            return max;
        else
            return min;
        
    }

    bool check(vector<int>& position, int m, int value){
        m--;
        int start = 0, end = 1, l = position.size();
        while(end<l){
            if(position[end]-position[start]>=value){
                start=end;
                m--;
            }
            if(m==0)
                return true;
            end++;
        }
        return false;
    }
};
```



