# No.50 数组中重复的数字

## 题目

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。 

## 题解

自己想到的是用map，参考了题解之后才发现这个题意，数组本身根据取值就可以直接当作一个hash来使用

```c++
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<1)
            return false;
        int index = 0;
        int temp;
        while(index<length){
            if(numbers[index] == index){
                index++;
                continue;
            }
            temp = numbers[index];
            if(numbers[temp]!=temp)
                swap(numbers, index, temp);
            else{
                *duplication = temp;
                return true;
            }
        }
        return false;
    }
private:
    void swap(int* numbers, int a, int b){
        int temp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = temp;
        return;
    }
};
```

