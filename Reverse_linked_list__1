ListNode* reverse(ListNode* head){

if((head == NULL)||(head->next == NULL)){

    return head;
}



ListNode* head1 = reverse(head->next);
//firstly going to last then reversing
head->next->next = head;
  head->next = NULL;

return head1;



}