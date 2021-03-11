class Solution {
public:
    vector<int> violence(vector<int>& nums, int target);
    vector<int> twoHash(vector<int>& nums, int target);
    vector<int> oneHash(vector<int>& nums, int target);
    vector<int> twoSum(vector<int>& nums, int target) {
        return oneHash(nums,target);
        //return twoHash(nums, target);
        //return violence(nums, target);
    }
};


//暴力解法
vector<int> Solution::violence(vector<int>& nums, int target)
{
    for(int i=0; i< nums.size()-1; i++)
    {
        for(int j = i+1; j< nums.size(); j++)
        {
            if(nums[i]+nums[j] == target)
                return {i,j};
        }
    }
    return {};
}

//两遍哈希:unorder_map保存的哈希表没有重复的键
vector<int> Solution::twoHash(vector<int>& nums, int target)
{
    //构建哈希表
    unordered_map<int, int> Map;
    for(int i=0; i< nums.size(); i++)
    {
        Map.insert(unordered_map<int, int>::value_type(nums[i],i));
    } 
    //插入找目标值
    // for(int i =0; i< nums.size(); i++)
    // {
    //     int temp = target - nums[i];
    //     if(Map.count(temp) > 0 && Map[temp] != i)
    //     {
    //         return {Map[temp],i};
    //     }
    // }
    for(int i=0;  i< nums.size(); i++)
    {
        int temp = target - nums[i];
        auto it = Map.find(temp);
        if(it != Map.end() && it->second !=  i)
        {
            return {i, it->second};
        }
    }
    return {};
}

//一遍哈希
vector<int> Solution::oneHash(vector<int>& nums, int target)
{
    unordered_map<int, int> Map;
    for(int i=0; i< nums.size(); i++)
    {
        int temp = target - nums[i];
        auto it = Map.find(temp);
        if(it != Map.end())
        {
            return {i, it->second};
        } 
        Map.insert(unordered_map<int,int>::value_type(nums[i], i));
    }
    return {};
}