# No.13 调整数组的位置

## 题目

调整数组位置，使得奇数在前偶数在后。

## 题解

刚开始想从前往后搜索到第一个偶数移除往最后塞，然而塞到最后就是偶数不断的变换位置。

那就试了试冒泡。

```c++
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int l = array.size();
        if(l == 0)
            return;
        for(int i=0; i< l-1; i++){
            for(int j = 0; j< l-1; j++){
                if(array[j]%2 == 0 && array[j+1]%2 == 1){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        return;
    }
};
```

emmm看了看题解，以为使用引用的原因就是不让使用新数组。。。

开个新数组存偶数奇数排好后偶数顺着插进去。。。妙啊