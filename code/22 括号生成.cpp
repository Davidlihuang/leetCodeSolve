#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void _generate(int level, int limit, string s, vector<string>& res); //枚举所有结果，筛选正确结果
    void cutBranch(int left, int right, int max, string s, vector<string>& res); //剪枝，避免无效枚举
    bool isValid(const string& s);
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        //_generate(0, 2*n, "", result); //
        cutBranch(0,0,n,"",result);
        return result;
    }
};


// 有效括号判定
bool Solution::isValid(const string& s)
{
    stack<char> chStack;
    if(s.size()%2 == 1 || s.size() == 0) return false;
    for(auto c: s)
    {
        if(c == ')')
        {
            if(chStack.empty() || chStack.top() != '(')
            {
                return false;
            }
            else
            {
                chStack.pop();
            }
        }
        else
        {
            chStack.push(c);
        }
    }
    return chStack.empty();
}

//递归列举所有结果，然后筛选
void Solution::_generate(int level, int limit, string s, vector<string>& res)
{
    //ternimate 
    if(level == limit)
    {
        if(isValid(s))
            res.push_back(s);
        return;
    }
    _generate(level+1, limit, s+'(', res);
    _generate(level+1, limit, s+')', res);

}

//剪枝
/*0, 剪枝和枚举再筛选相比：(176ms, 171.8MB)--> (4ms, 13.3MB) 性能提升了44倍， 消耗空间减少了12倍
* 1, '('  数量最大为：max
* 2, ')'  当左括号数量大于右括号数量才能增加的右括号才是合法的
*/

void Solution::cutBranch(int left, int right, int max, string s, vector<string>& res)
{
    if(left == max && right == max)
    {
        res.push_back(s);
        return;
    }

    if(left < max)
    {
        cutBranch(left+1, right, max, s+'(', res);
    }
    if(right < left && right < max)
    {
        cutBranch(left, right+1, max, s+')', res);
    }
}