/*
 * @lc app=leetcode.cn id=967 lang=cpp
 *
 * [967] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int i,j,k;
        vector<int> result;
        int sum;
        if(N == 0){
            return result;
        }
        if(N == 1){
            for(i = 0;i<=9;i++){
                sum = i;
                number(1, sum, N, K, result);
            } 
        }
        else{
            for(i = 1;i<=9;i++){
                sum = i;
                number(1, sum, N, K, result);
            }  
        }
        return result;
    }

    void number(int l, int now, int N, int K, vector<int>& result){
        if(l == N) {
            result.push_back(now);
            return;
        }
        int temp = now%10;
        if( temp + K <= 9){
            number(l+1, now*10 + temp +K, N, K, result);
        }
        if( temp - K >= 0 && K!= 0){
            number(l+1, now * 10 +temp - K, N, K, result);
        }
        return;
    }
};
// @lc code=end

