
// C program for array implementation of stack 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

// 애초에 첨부터 stack의 크기를 만들어준다 
// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
// create Stack이 되게재밌는데 
// 애초에 array랑 top이랑 분리했었는데 그러지않고 
// a
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 
} 
/*
array랑 top이랑 분리하징낳고 
stack array에 할당하고 top을 -1로만들고 
capacity만큼 할당하면된다 .

stack을 이용해서 큐를 구현할려면 top을 조지면될거같은데 
배열의 요소에 head를 두고 tail을 하는거지 
근데 이런경우 첨 인덱스가 점점 뒤로 밀린다 .
이걸 고치기 위해서 원형으로 만드는거지 .

*/