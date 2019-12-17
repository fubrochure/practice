/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        if(l == 0){
            return "";
        }
        int result = 1;
        int re_head = 0;
        int re_len = 1;
        int i, j, k;
        
        int head = 0, tail = 0;
        for(i = 1, j = 0; i < l; i++){
            //std::cout<<head<<" "<< i <<endl ;
            if(head > 0){
                if(s[head-1] == s[i]){
                    cout<<head<<" "<< i ;
                    head--;
                    cout<<" s[head-1] == s[i] "<<endl;
                }
                else{
                    if(s[head]!=s[i]){
                        cout<<head<<" "<< i;
                        head = i;
                        cout<<" s[head]!=s[i] "<<endl;
                    }
                    else{
                        cout<<head<<" "<< i <<" nothing"<<endl ;
                    }
                    
                }
            }  
            else{
                if(s[head]!=s[i]){
                    cout<<head<<" "<< i;
                    head = i;
                    cout<<" s[head]!=s[i] "<<endl;
                }
                else{
                    cout<<head<<" "<< i <<" nothing"<<endl ;
                }
            }
            
            
            j = i- head + 1;
            if(j>=re_len){
                re_head = head;
                re_len = j;
            }
            
        } 
        return s.substr(re_head,re_len);
    }
};
// @lc code=end

