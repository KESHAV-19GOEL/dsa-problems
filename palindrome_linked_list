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
    bool isPalindrome(ListNode* head) {
        
//include edge cases
if((head == NULL)||(head->next==NULL))
return true;

ListNode* fptr = head;
ListNode* sptr = head;

while((fptr->next != NULL)&&(fptr->next->next!=NULL))
{
    fptr = fptr->next->next;
    if(fptr->next != NULL)
sptr = sptr->next;




}
ListNode* mid ;
if(fptr->next == NULL)
mid= sptr->next->next;

else
mid = sptr->next;



ListNode* prev = NULL;
ListNode* curr = head;
ListNode* forw = head;

while(curr!= sptr){
forw = curr->next;
curr->next = prev;
prev = curr;
curr  = forw;


}
sptr->next = prev;

while(sptr->val == mid->val){

if((mid->next == NULL )&&(sptr->next == NULL)){
return true;}

sptr = sptr->next;
mid = mid->next;

}

return false;













    }
};