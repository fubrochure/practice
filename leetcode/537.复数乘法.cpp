/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int i = 0;
        int n1 = 0, n2 = 0, m1 = 0, m2 = 0;
        int flag = 1;
        while(a[i]!='+'){
            if (a[i]=='-'){
                flag = -1;
                i++;
                continue;
            }
            n1 *= 10;
            n1 += a[i]-'0';
            i++;
        }
        i++;
        n1 *= flag;
        //std::cout<<i<<endl;
        flag = 1;
        while(a[i] !='i'){
            if (a[i]=='-'){
                flag = -1;
                i++;
                continue;
            }
            //std::cout<<a[i]<<endl;
            n2 *= 10;
            n2 += a[i]-'0';
            i++;
        }
        n2 *= flag;
        //std::cout<<"n2"<<endl;
        flag = 1;
        i = 0;
        while(b[i]!='+'){
            if (b[i]=='-'){
                flag = -1;
                i++;
                continue;
            }
            m1 *= 10;
            m1 += b[i]-'0';
            i++;
        }
        m1*=flag;
        flag =1;
        i++;
        while(b[i] !='i'){
            if (b[i]=='-'){
                flag = -1;
                i++;
                continue;
            }
            m2 *= 10;
            m2 += b[i]-'0';
            i++;
        }
        m2 *= flag;
        cout<<n1 <<" "<<n2<<" "<<m1<<" "<< m2<<endl;
        int r1, r2;
        r1 = n1*m1 - n2*m2;
        r2 = n1*m2 + n2*m1;
        return std::to_string(r1)+"+"+std::to_string(r2)+"i";
    }
};
// @lc code=end

