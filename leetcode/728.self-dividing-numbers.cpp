/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (71.38%)
 * Likes:    465
 * Dislikes: 250
 * Total Accepted:    92.8K
 * Total Submissions: 130K
 * Testcase Example:  '1\n22'
 *
 * 
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 * 
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 * 
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * 
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 * 
 * Example 1:
 * 
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 
 * Note:
 * The boundaries of each input argument are 1 .
 * 
 */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++){
            if (valid(i)){
                ans.push_back(i);
            }
        }
        return ans;        
    }
    bool valid(int n){
        int ori = n;
        int cur = 0;
        while(n){
            cur = n % 10;
            n = n/10;
            if (cur == 0){
                return false;
            }
            if (ori % cur != 0){
                return false;
            }
        }
        return true;
    }
};

