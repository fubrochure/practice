# No.1550 存在连续三个奇数的数组

给你一个整数数组 `arr`，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 `true` ；否则，返回 `false` 。 

202周赛第一题

签到题，双指针完事了

或者一个count变量用if处理也行

```c++
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int l = arr.size();
        if(l<3)
            return false;
        int start = 0, end =0;
        while(end<l){
            if(arr[end]%2 == 1)
                end++;
            else
                start = ++end;
            if(end - start == 3)
                return true;
        }
        return false;
    }
};
```

