// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeList(ListNode *list1, ListNode *list2){
        ListNode *newHead = new ListNode(), *tail = newHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != nullptr)
            tail->next = list1;
        else if(list2 != nullptr)
            tail->next = list2;
        
        return newHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        else if(lists.size() == 1 && lists[0] == nullptr)
            return nullptr;
        
        while(lists.size() > 1){
            vector<ListNode *> mergedLists;
            
            for(int i=0; i<lists.size(); i+=2){
                ListNode *list1 = lists[i];
                ListNode *list2 = (i+1<lists.size())? lists[i+1] : nullptr;
                
                mergedLists.push_back(mergeList(list1, list2));
            }
            lists = mergedLists;
        }
        
        return lists[0];
    }
};
