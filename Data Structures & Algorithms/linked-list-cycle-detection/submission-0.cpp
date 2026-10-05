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
    bool hasCycle(ListNode *head) {
        // 1. 起點：烏龜和兔子都在 head 準備
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 2. 迴圈：設定兔子的安全防護網 (你剛剛寫出來的防呆機制)
        while ( fast!=nullptr && fast->next != nullptr) {
            
            // 3. 移動：烏龜走一步，兔子跳兩步
            slow = slow->next;
            fast = fast->next->next;
            
            // 4. 抓賊：如果烏龜和兔子相遇了，代表有迴圈
            if ( fast == slow || slow == fast) {
                return true;
            }
        }
        
        // 5. 結案：兔子順利跑出迴圈走到盡頭了，代表沒迴圈
        return false;
    }
};
