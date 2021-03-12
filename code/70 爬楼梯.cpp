#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int ruleRecur(int n); //暴力递归，O(2^n)时间复杂度爆炸
    int memerialHelper(unordered_map<int,int>& memerial, int n); //存在重叠子问题，可以用备忘录保存状态
    int Dphelper(int n); //存在重叠子问题，可以使用动态规划
    int climbStairs(int n) {
        //unordered_map<int,int> memerial{};
        //return memerialHelper(memerial, n);
        return Dphelper(n);
        //return ruleRecur(n);
    }
};

//暴力递归，
int Solution::ruleRecur(int n)
{
    if(n < 3) return n;
    return ruleRecur(n-1) + ruleRecur(n-2);
}

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