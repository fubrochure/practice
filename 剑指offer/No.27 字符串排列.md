# No.27 字符串排列

## 题目

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 

## 解题

本题就是字典序。

说来惭愧在交之前一直以为普通的全排列就是字典序，要是不写这题不知道以后要白给多少。

先来个普通全排列

```c++
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> results;
        int l = str.length();
        change(results, str,0, l-1);
        return results;
    }
    
    void change(vector<string>& results, string& str, int flag, int l){
        if(flag == l){
            auto iter = find(results.begin(), results.end(), str);
            if(iter == results.end()){
                results.push_back(str);
            }
            return;
        }
        for(int i=flag; i<=l; i++){
            swap(str, flag, i);
            change(results, str, flag+1, l);
            swap(str, flag, i);
        }
        return;
    }
    
    void swap(string& str, int a, int b){
        char temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }
};
```

