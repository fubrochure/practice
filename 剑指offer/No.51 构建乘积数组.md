# No.51 构建乘积数组

## 题目

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];） 

## 题解

最简单的暴力全部算一遍，但明显浪费了许多时间，稍稍利用备忘录优化一下,对于所有的可能用到的数字算一遍记住

```c++
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<vector<int>> data(n, vector<int>(n));
        for(int l = 0; l<n; l++){
            for(int i=0; i+l<n;i++){
                int j = i+l;
                if(i==j){
                    data[i][j]=A[i];
                }
                else{
                    data[i][j] = data[i][j-1] * A[j];
                }
            }
        }
        vector<int> result(n);
        for(int i = 0;i<n;i++){
            result[i] = get_data(data, 0, i-1)*get_data(data, i+1, n-1);
        }
        return result;
    }

private:
    int get_data(vector<vector<int>>& data, int a, int b){
        if(a>b)
            return 1;
        else
            return data[a][b];
    }
};
```

