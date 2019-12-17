/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        int result[1010];
        result[0] = 0;
        result[1] = 0;
        int i,j,k;
        int temp;
        int sum;
        for(i=2;i<=n;i++){
            //cout<<temp<<endl;
            result[i] = i;
            for(j=i-1;j>0; j--){
                if(i%j == 0){
                    sum = result[j]+ i/j;
                    result[i] = sum;
                    break;
                }
            }
            //cout<< i<<" "<<result[i]<<endl;
        }
        return result[n];
    }
    
};
// @lc code=end

