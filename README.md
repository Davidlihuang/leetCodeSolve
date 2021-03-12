# leetCodeSolve
leetcode解题记录
## 1. 两数之和
- 题目描述
- 审题
- 解题思路
- 关键代码片段
## 20. 有效括号
- 题目描述
- 审题
- 解题思路
- 关键代码片段
## 22. 括号生成
- 题目描述
```txt
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合

示例：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```
- 审题
- 解题思路
```txt
1. 枚举所有的括号组合，通过判断**有效括号** 筛选有效括号组合。
2. 利用剪枝的方法，避免无效的枚举。直接得到有效括号组合
    ①、左括号数量必须小于n
    ②、左括号先于右括号出现，且只有当右括号的数量小于左括号的数量时才允许添加右括号，并且需要保证右括号的数量小于n
    ③、利用①和②两个条件就可以有选择的添加左右括号，避免无效的枚举。
```
- 关键代码片段
**①、枚举+ 筛选**
```cpp

//递归列举所有结果，然后筛选
void Solution::_generate(int level, int limit, string s,vector<string>& res)
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

```
**②、剪枝**
```cpp
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
```
**③、 有效括号盘判定**
```cpp
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
```
## 70. 爬楼梯
- 题目描述
```txt
- 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
- 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
   
注意：给定 n 是一个正整数。
```
- 审题
```txt
- 爬n阶楼梯
- 每次只能爬 1阶 或者 2阶
- 不能倒退
```
- 解题思路
```txt
到达目标台阶有两种走法
1. 从倒数第一个台阶，迈一步到达
2. 从倒数第二个台阶，迈两步到达
```
- 关键代码片段

**①、暴力递归**
```cpp
//暴力递归，
int Solution::ruleRecur(int n)
{
    if(n < 3) return n;
    return ruleRecur(n-1) + ruleRecur(n-2);
}
```
**③、备忘录保存重叠解**
```cpp
//存在「重叠子问题」，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算
int Solution::memerialHelper(unordered_map<int,int>& memerial, int n)
{
    if(n<3) return n;
    if(memerial.count(n)) 
    {
        return memerial[n];
    }    
    else
    {
        memerial[n] = memerialHelper(memerial,n-1) + memerialHelper(memerial,n-2); 
        return memerial[n];
    }
}
```
**③、动态规划**
```cpp
//动态规划
int Solution::Dphelper(int n)
{
    int dp1=1, dp2=2;
    int res = 0;
    if(n < 3) return n;
    for(int i = 3; i< n+1;i++)
    {
        res =dp1 + dp2;
        dp1 = dp2;
        dp2 = res;
    }
    return res;
}
```
## 141. 环形链表
- 题目描述
- 审题
- 解题思路
- 关键代码片段
## 142. 环形链表II
- 题目描述
- 审题
- 解题思路
- 关键代码片段
## 206. 反转链表
- 题目描述
- 审题
- 解题思路
- 关键代码片段
## 
