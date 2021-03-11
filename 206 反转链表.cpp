/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* iterationHelper(ListNode* head);
    ListNode* iteraToRecurHelper(ListNode* pre, ListNode* cur);
    ListNode* recursionHelper(ListNode* head);

    ListNode* reverseList(ListNode* head) {
        //return iterationHelper(head);
        return iteraToRecurHelper(nullptr, head);
        //return recursionHelper(head);
    }
};

//迭代版本
ListNode* Solution::iterationHelper(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* tmp = nullptr; //指向未反转链表部分的头结点
    while(cur)
    {
        tmp = cur->next; //标记新头
        cur->next = pre; // 更改指针
            
        pre = cur;
        cur = tmp;
    }
    return pre;
}

//递归版本
ListNode* Solution::recursionHelper(ListNode* head)
{
    if(head== nullptr || head->next == nullptr)
        return head;
    ListNode* cur = recursionHelper(head->next);
    head->next->next = head;
    head->next = nullptr;
    return cur;
}

//双指针改递归版本
ListNode* Solution::iteraToRecurHelper(ListNode* pre, ListNode* cur)
{
    //遍历完成后返回头结点
    if(cur == nullptr)
        return pre;

    //更改相邻两个指针的指向
    ListNode* tmp = cur->next;
    cur->next = pre;

    //更新pre 和cur 的指针指向，并进入下一层递归
    return iteraToRecurHelper(cur, tmp);
}
