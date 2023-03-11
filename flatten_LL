/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

  if(head == NULL){
  return head;
  }

Node* temp = head;
Node* chotahead1;
while(temp != NULL){

if(temp->child == NULL)
{temp = temp->next;}

else{

chotahead1 = flatten(temp->child);
Node* temphead = temp;    
Node* chotahead2 = temp->next;
    
    
   /*if((chotahead1 != NULL) && (chotahead2 != NULL)){
  if(chotahead2->val < chotahead1->val){
temphead->next = chotahead2;
chotahead2->prev = temphead;
temphead = chotahead2;
chotahead2 = chotahead2->next;
  }   
else{
temphead->next = chotahead1;
chotahead1->prev = temphead;
temphead = chotahead1;
chotahead1 = chotahead1->next;
}

   }*/
    while(chotahead1 != NULL)
   {temphead->next = chotahead1;
    chotahead1->prev = temphead;
    temphead = chotahead1;   
    chotahead1 = chotahead1->next;
   }
    while(chotahead2 != NULL){
       temphead->next = chotahead2;
    chotahead2->prev = temphead;
    temphead = chotahead2;
    chotahead2 = chotahead2->next; 
    }
   
   temp->child = NULL;
   temp = temp->next;


}

}









return head;

    }
};