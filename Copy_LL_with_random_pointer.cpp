/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

public:
    Node* copyRandomList(Node* head) {
      if(head == NULL)
      { return NULL;}
        Node* temp = head;

//     Cloning the LL
        Node* clone = new Node(temp->val);
        Node* clonehead = clone;
        clone->val = temp->val;
        temp = temp->next;
        while(temp != NULL){
    
    Node* n1 = new Node(temp->val);
    n1->val = temp->val;
    clone->next = n1;
    clone = clone->next;
temp = temp->next;
        
        }

// joining the 2 LL
Node* original = head;
Node* clonell = clonehead;
Node* next;

while(clonell != NULL){
    next= original->next;
original->next = clonell;
original = next;
next = clonell->next;
clonell->next = original;
clonell = next;

}

// joining random pointers
 original = head;
 clonell = clonehead;

while(original != NULL){
    if(original->random != NULL)
    {original->next->random = original->random->next;}

    else{
        original->next->random = NULL;
    }
    original = original->next->next;
}

// seperating LL

original = head;
 clonell = clonehead;

while((clonell != NULL)&&(clonell->next != NULL)){

original->next = clonell->next;
original  = original->next;
 
 
clonell->next = original->next;
clonell  = clonell->next;

}
original->next = NULL;

return clonehead;
    }
};