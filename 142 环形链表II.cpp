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
    ListNode *hashFunc(ListNode* head);
    ListNode *slowQuickFunc(ListNode* head);
    ListNode *detectCycle(ListNode *head) {
        //return hashFunc(head);
        return slowQuickFunc(head);
    }
};
//快慢指针： head到入环点的距离 == slow相遇后的指针到入环点的距离
ListNode* Solution::slowQuickFunc(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next)
    {
        fast= fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            ListNode* ptr  = head;
            while(slow != ptr)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

//返回哈希表中已经存在的结点指针，就是环的入口点
ListNode* Solution::hashFunc(ListNode* head)
{
    ListNode* wanderer = head;
    unordered_set<ListNode*> nodeSet;
    while(wanderer)
    {
        if(nodeSet.count(wanderer))
            return wanderer;
        nodeSet.insert(wanderer);
        wanderer = wanderer->next;
    }
    return nullptr;
}