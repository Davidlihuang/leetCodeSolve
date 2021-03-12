/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //快慢指针解法，如果存在环，快指针终究会追上慢指针
    bool helper1(ListNode* head);
    bool helper2(ListNode* head);
    //哈希表解法，遍历过的结点保存在哈希表中，如果存在环，那么一定可以在表中找当相同的结点
    bool helper3(ListNode* head);

    bool hasCycle(ListNode *head) {
        return helper1(head);
        //return helper2(head);
        //return helper3(head);
    }
};

//快慢指针同时出发
bool Solution::helper1(ListNode* head)
{
    ListNode* slowPointer = head;
        ListNode* quickPointer = head;
        //空列表或只有一个结点且不成环，直接结束
        while((quickPointer != nullptr) && (quickPointer->next != nullptr))
        {
            slowPointer = slowPointer->next;
            quickPointer = quickPointer->next->next;
            if(slowPointer == quickPointer)
            {
                return true;
            }
        }
    return false;
}

//初始条件快指针比慢指针领先一步
bool Solution::helper2(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return false;
    
    ListNode* slow = head;
    ListNode* quick = head->next;
    while(quick && quick->next)
    {
        if(slow == quick)
            return true;
        slow = slow->next;
        quick = quick->next->next;
    }
    return false;
}

// 使用哈希表保存遍历过的结点，若当前结点能够在表中找到，那么说明有环
bool Solution::helper3(ListNode* head)
{
    unordered_set<ListNode*> NodeSet;
    ListNode* wanderer = head;
    while(wanderer)
    {
        if(NodeSet.count(wanderer))
            return true;
        NodeSet.insert(wanderer);
        wanderer = wanderer->next;
    }
    return false;
}