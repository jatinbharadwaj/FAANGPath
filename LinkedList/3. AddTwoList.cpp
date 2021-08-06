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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *newll = new ListNode(-1);
        ListNode *dummyhead = newll;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            newll->next = new ListNode(sum % 10);
            newll = newll->next;
            carry = sum / 10;
        }
        if (carry)
        {
            newll->next = new ListNode(carry);
        }
        return dummyhead->next;
    }
};