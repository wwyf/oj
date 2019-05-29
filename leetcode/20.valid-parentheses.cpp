/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.49%)
 * Likes:    2893
 * Dislikes: 144
 * Total Accepted:    591.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    map<char, int> map_r;
    vector<char> openSymbols;
    vector<char> closeSymbols;
    Solution()
    {
        openSymbols = {'(', '[', '{'};
        closeSymbols = {')', ']', '}'};
        map_r['('] = 1;
        map_r[')'] = 1;
        map_r['{'] = 2;
        map_r['}'] = 2;
        map_r['['] = 3;
        map_r[']'] = 3;
    }
    bool isValid(string s)
    {
        if (s.empty())
        {
            return true;
        }
        stack<char> symbol_stack;
        for (char c : s)
        {
            if (isOpen(c))
            {
                symbol_stack.push(c);
            }
            else if (isClose(c))
            {
                if (symbol_stack.empty())
                {
                    return false;
                }
                char top = symbol_stack.top();
                symbol_stack.pop();
                if (!isCorrect(top, c))
                {
                    return false;
                }
            }
        }
        if (symbol_stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }
    bool isOpen(char c)
    {
        for (char i : openSymbols)
        {
            if (c == i)
            {
                return true;
            }
        }
        return false;
    }
    bool isClose(char c)
    {

        for (char i : closeSymbols)
        {
            if (c == i)
            {
                return true;
            }
        }
        return false;
    }
    bool isCorrect(char l, char r)
    {
        if (map_r[l] == map_r[r])
        {
            return true;
        }
        return false;
    }
};

class Solution2
{
public:
    bool isValid(string s)
    {
        stack<char> stack;

        if (s.length() == 0)
        {
            return true;
        }
// 从solution里看到的解法，下面的这个判断省下了很多时间。
        if (s.length() == 1)
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            cout << c;
            if (c == '}' || c == ')' || c == ']')
            {
                if (stack.size() == 0)
                    return false;
                if (c == '}' && stack.top() != '{')
                    return false;
                if (c == ')' && stack.top() != '(')
                    return false;
                if (c == ']' && stack.top() != '[')
                    return false;
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }
        // cout << "reached end";
        if (stack.size() == 0)
            return true;
        return false;
    }
};

// 简明的写法
// 将一些细节隐藏了起来
class Solution3 {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};


