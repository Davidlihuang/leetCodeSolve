/***题目描述
 * 
**
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
bool isValid_solution2(string s)
{
    stack<char> strStack;
    int strLen = s.size();
    unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}};

    if (strLen % 2 == 1)
        return false;

    for (auto c : s)
    {
        if (pairs.count(c))
        {
            if (strStack.empty() || strStack.top() != pairs[c])
            {
                return false;
            }
            else
            {
                strStack.pop();
            }
        }
        else
        {
            strStack.push(c);
        }
    }
    return strStack.empty();
}
bool isValid_solution1(string s)
{
    if (s.size() % 2 == 1)
        return false;
    std::stack<char> strStack;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            strStack.push(c);
        }
        if (!strStack.empty())
        {
            if (strStack.top() == '(' && c == ')')
            {
                strStack.pop();
            }
            if (!strStack.empty() && strStack.top() == '{' && c == '}')
            {
                strStack.pop();
            }
            if (!strStack.empty() && strStack.top() == '[' && c == ']')
            {
                strStack.pop();
            }
        }
        else
        {
            return false;
        }
    }
    return strStack.empty();
}

int main()
{
    string s("()({})");
    cout << isValid_solution2(s) << endl;
    cout << isValid_solution1(s) << endl;
    return 0;
}