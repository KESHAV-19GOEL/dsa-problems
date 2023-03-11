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
    ListNode* deleteDuplicates(ListNode* head) {
   
   if((head == NULL)||(head->next == NULL))
   return head;
   
   ListNode* dummy = new ListNode;     
ListNode* prev = dummy;
prev->next = NULL;
ListNode* curr = head;
ListNode* forw = head->next;
bool flag = false;

while(forw != NULL){

while(curr->val == forw->val)
{
    curr = forw;
    forw = forw->next;
    if(forw == NULL)
 {  prev->next = NULL;
     return dummy->next;}
    flag = true;
}
 
if(flag){
    curr = forw;
   
    forw = forw->next;
    flag = false;

}
else if(prev->next == NULL){
  
    prev->next = curr;
    prev = curr;
    curr = forw;
    forw = forw->next;
}

/*while(curr->val == forw->val)
{
    curr = forw;
    forw = forw->next;
    flag = true;
}

if(flag){
    curr = forw;
    forw = forw->next;
    flag = false;
    continue;
}*/
else{

prev->next = curr;
prev = curr;
curr = forw;
forw = forw->next;

}

}
prev->next = curr;
if(dummy->next == NULL)
return NULL;
return dummy->next;


    }
};