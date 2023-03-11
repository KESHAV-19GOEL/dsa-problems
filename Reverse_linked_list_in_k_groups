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
    private:
    void ReverseKGroup(ListNode* head, int k,ListNode* start,ListNode* tail){
ListNode* temp = tail;


for(int i=1;i<k;i++){
    if(temp == NULL)
break;
temp = temp->next;

}
if(temp == NULL)
{start->next = tail;
return ;}
ListNode* forw ;
ListNode* prev = tail ;
ListNode* curr = tail->next ;



for(int i=1;i<k;i++){
forw = curr->next;
curr->next = prev;
prev = curr;
curr = forw;
}




start->next = temp;

ReverseKGroup(head,k,tail,curr);

}














public:
    ListNode* reverseKGroup(ListNode* head, int k) {
if(k<=1){
return head;

}
ListNode* prev = head ;
ListNode* curr = prev->next ;
ListNode* forw  ;

for(int i=1;i<k;i++){
forw = curr->next;
curr->next = prev;
prev = curr;
curr = forw;
}
ReverseKGroup(head,k,head,forw);

return prev;
    }
};