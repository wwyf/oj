/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        int len = S.size();
        if (len <= 1){
            return S;
        }
        int cnt = 0; // i : the length of stack
        // S[cnt-1] the top of stack
        int i = 0;
        for (int i = 0; i < len; i++){
            if (cnt == 0){
                // 如果栈是空的，那就直接把一个字符放进去就得了
                S[cnt] = S[i];
                cnt++;
                continue;
            }
            // 检查当前字符与栈顶的关系
            if (S[cnt-1] != S[i]){
                // 如果栈顶不等于当前字符
                S[cnt] = S[i]; // 将字符放入栈顶
                cnt++; // 栈变长
            } else {
                // 栈顶等于当前字符
                // 将字符从栈顶去掉，并忽略当前字符
                cnt--;
            }
        }
        S.resize(cnt);
        return S;
    }
};
// @lc code=end

////////////////////////////////////////////////////////////////
// method 1
// #include <string>
// using namespace std;
// class Solution {
// public:
//     string removeDuplicates(string S) {
//         int len = S.size();
//         if (len <= 1){
//             return S;
//         }
//         int i = 0;
//         for (i = 0; i < len-1; i++){
//             if (S[i] == S[i+1]){
//                 // 删除这两个字符，得到一个新字符串
//                 // S.substr();
//                 S.erase(i, 2);
//                 break;
//             }
//         }
//         if(i == len-1){
//             return S;
//         } else{
//             return removeDuplicates(S);
//         }
//     }
// };

///////////////////////////////////////////////////////
// method 2
// #include <string>
// using namespace std;
// class Solution {
// public:
//     string removeDuplicates(string S) {
//         int len = S.size();
//         if (len <= 1){
//             return S;
//         }
//         int i = 0;
//         int should_continue=1;
//         while(should_continue){
//             should_continue = 0;
//             for (i = 0; i < len-1; i++){
//                 if (S[i] == S[i+1]){
//                     // 删除这两个字符，得到一个新字符串
//                     S.erase(i, 2);
//                     should_continue = 1;
//                     break;
//                 }
//             }
//         }
//         return S;
//     }
// };

/////////////////////////////////////
// method 3
// #include <string>
// using namespace std;
// class Solution {
// public:
//     string removeDuplicates(string S) {
//         int len = S.size();
//         if (len <= 1){
//             return S;
//         }
//         int i = 0;
//         while (i != len){
//             if (S[i] == S[i+1]){
//                 // 删除这两个字符，得到一个新字符串
//                 S.erase(i, 2);
//                 // 考虑到i-1项可能和后面的重复，因此i要在可减的情况下减一
//                 if (i > 0){
//                     i--;
//                 }
//             } else {
//                 // 如果不想等，那就直接往后找
//                 i++;
//             }
//         }
//         return S;
//     }
// };