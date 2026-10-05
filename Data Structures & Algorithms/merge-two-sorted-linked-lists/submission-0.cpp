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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 第一步：建立站牌 (dummy) 和新隊伍的隊尾指標 (curr)
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        // 第二步：只要兩邊都還有人，就繼續比大小
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;      // 牽走 list1 的人
                list1 = list1->next;     // list1 手指往後移
            } else {
                curr->next = list2;      // 牽走 list2 的人
                list2 = list2->next;     // list2 手指往後移
            }
            curr = curr->next;           // 新隊伍變長了，隊尾手指也要往後移
        }
        
        // 第三步：迴圈結束，把剩下的尾巴直接接上去
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        // 第四步：準備交出答案
        ListNode* ans = dummy->next; // 先記住真正的開頭
        delete dummy;                // (C++好習慣) 把我們借用的假箱子還給系統，避免佔用記憶體
        return ans;                  // 交出答案！
    }
};
