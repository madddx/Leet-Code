class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> map;
        for(int i = 0, n = nums.size(); i < n; ++i) map.set(nums[i]);
        while(head && map.test(head->val)) head = head->next;
        ListNode *curr = head;
        while(curr && curr->next){
            if(map.test(curr->next->val)) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return head;
    }
};
