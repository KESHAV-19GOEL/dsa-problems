#include <bits/stdc++.h> 
class NStack
{

int n;
int s;
int* next;
int *arr;
int* top;
int freespot;


public:
    // Initialize your data structure.
    NStack(int N, int S)
    {   n = N;
    s = S;
      arr = new int[S];
      top = new int[N] ;
      next = new int[S];

      for (int i = 0; i < n; i++) {
top[i] = -1;}


      
     
     freespot = 0;
   
    for(int i=0;i<s;i++){

   // next[i++] = i;
next[i] = i+1;

    }
    next[s-1] = -1;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1)
        return false;

    
   // find index
    int index = freespot;
   //update value
    arr[index] = x;f

// updating freespot
    freespot = next[index];
    
   // next will be now made to top
    next[index] = top[m-1];
    
    //updating top for that particular array
    top[m-1] = index;

  return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    { 
        
        if(top[m-1] == -1)
        return  -1;
        
     int  index = top[m-1];

      top[m-1] = next[index];

      next[index] = freespot;

     freespot = index;
       
return arr[index]; 
    }
};


