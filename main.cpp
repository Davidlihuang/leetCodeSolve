#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<string> res;
// 有效括号判定
bool isValid(string s)
{
    unordered_map<char, char> charMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    stack<char> chStack;

    if(s.size()%2 == 1) return false;
    for(auto c: s)
    {
        if(charMap.count(c))
        {
            if(chStack.empty() || chStack.top() != charMap[c])
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

//辅助函数递归生成括号对
vector<string> _generate(int level, int limit, string s)
{
    //ternimate 
    if(level == 2*limit)
    {
        if(isValid(s))
            res.push_back(s);
        return res;
    }

    _generate(level+1,limit,s+'(');
    _generate(level+1, limit, s+')');
        
    //process

    //drill down

    //clean
    return {};
}

vector<string> generateParentTHesis(int n)
{
    return _generate(0,n,"");
}

int main()
{

    generateParentTHesis(3);
    for(auto c:res)
        cout << c << endl;


    return 0;
}


