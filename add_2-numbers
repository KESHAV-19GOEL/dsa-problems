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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

     if(l1 == NULL)
     return l2;

       if(l2 == NULL)
     return l1;

int carry =0;
ListNode* ans = new ListNode;
ListNode* answer = ans;
    while((l1 != NULL)&&(l2 != NULL))
    {
    int insert = (l1->val + l2->val + carry)%10;
ListNode* temp = new ListNode;
temp->val = insert;
ans->next = temp; 
ans= ans->next;

  carry = (l1->val + l2->val + carry)/10;
l1 = l1->next;
l2 = l2->next;
}
ListNode* temp1;
if(l1 == NULL)
{ temp1 = l2;}

    else{ temp1 = l1;}

while(temp1 != NULL){
 int insert = (temp1->val + carry)%10;
ListNode* temp = new ListNode;
temp->val = insert;
ans->next = temp; 
ans= ans->next;

  carry = (temp1->val + carry)/10;
temp1 = temp1->next;

}
if(carry ==1){
    ListNode* temp = new ListNode;
temp->val = 1;
ans->next = temp; 
}
return answer->next;

    }
};