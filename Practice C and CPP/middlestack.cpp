#include<bits/stdc++.h>
using namespace std;
//Doubly Linked list
class DLLNode{
 public: 
  DLLNode *prev;
  int data;
  DLLNode *next;
};
/* Representation of the stack data structure that supports findMiddle() in O(1) time. The Stack is implemented using Doubly Linked List. It maintains pointer to head node, pointer to 
middle node and count of nodes */
class myStack{
public:
 DLLNode *head;
 DLLNode *mid;
 int count;
};

//Function to create the stack data structure

myStack *createMyStack()
{
 myStack *ms = new myStack();
 ms->count;
 return ms;
};

void push(myStack *ms,int new_data)
{
 DLLNode* new_DLLNode = new DLLNode();
 new_DLLNode->data = new_data;
 new_DLLNode->prev = NULL;
 new_DLLNode->next = ms->head;
 ms->count += 1;
 if(ms->count ==1)
 {
  ms->mid= new_DLLNode;
 }
 else
 {
  ms->head->prev = new_DLLNode;
  if(!(ms->count & 1))
   ms->mid = ms->mid->prev;
 }
 ms->head = new_DLLNode;
}int pop(myStack *ms)  
{  
    /* Stack underflow */
    if (ms->count == 0)  
    {  
        cout<<"Stack is empty\n";  
        return -1;  
    }  
  
    DLLNode *head = ms->head;  
    int item = head->data;  
    ms->head = head->next;  
  
    // If linked list doesn't  
    // become empty, update prev  
    // of new head as NULL  
    if (ms->head != NULL)  
        ms->head->prev = NULL;  
  
    ms->count -= 1;  
  
    // update the mid pointer when  
    // we have odd number of  
    // elements in the stack, i,e  
    // move down the mid pointer.  
    if ((ms->count) & 1 )  
        ms->mid = ms->mid->next;  
  
    free(head);  
  
    return item;  
}  
  
// Function for finding middle of the stack  
int findMiddle(myStack *ms)  
{  
    if (ms->count == 0)  
    {  
        cout << "Stack is empty now\n";  
        return -1;  
    }  
  
    return ms->mid->data;  
}  
  
 
int main()  
{  
    /* Let us create a stack using push() operation*/
    myStack *ms = createMyStack();  
    push(ms, 11);  
    push(ms, 22);  
    push(ms, 33);  
    push(ms, 44);  
    push(ms, 55);  
    push(ms, 66);  
    push(ms, 77);  
  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Middle Element is " << findMiddle(ms) << endl;  
    return 0;  
}  
