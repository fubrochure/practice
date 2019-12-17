/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int size = deck.size();
        int target = 0;
        vector<int> result(size,0);
        result[0] = deck[target];
        target++;
        int flag = 0;
        int p = 0;
        while(target < size){
            while(flag<2){
                p = (p+1)%size;
                if(result[p] == 0){
                    flag++;
                }
            }
            flag = 0;
            result[p] = deck[target++];
        }
        return result;
    }
};
// @lc code=end

