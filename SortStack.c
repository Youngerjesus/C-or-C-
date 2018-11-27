


// C program to sort a stack using recursion 
#include <stdio.h> 
#include <stdlib.h> 
  
// Stack is represented using linked list 
struct stack 
{ 
    int data; 
    struct stack *next; 
}; 
  
// Utility function to initialize stack 
void initStack(struct stack **s) 
{ 
    *s = NULL; 
} 
  
// Utility function to chcek if stack is empty 
int isEmpty(struct stack *s) 
{ 
    if (s == NULL) 
        return 1; 
    return 0; 
} 
  
// Utility function to push an item to stack 
// void push(struct stack **s , int x)
void push(struct stack **s, int x) 
{ 
    struct stack *p = (struct stack *)malloc(sizeof(*p)); 
  
    if (p == NULL) 
    { 
        fprintf(stderr, "Memory allocation failed.\n"); 
        return; 
    } 
  
    p->data = x; 
    p->next = *s; 
    *s = p; 
} 
  
// Utility function to remove an item from stack 
int pop(struct stack **s) 
{ 
    int x; 
    struct stack *temp; 
  
    x = (*s)->data; 
    temp = *s; 
    (*s) = (*s)->next; 
    free(temp); 
  
    return x; 
} 
  
// Function to find top item 
int top(struct stack *s) 
{ 
    return (s->data); 
} 

// x는 item값이네 x가 top(*s) 보다 크다면 push   
// Recursive function to insert an item x in sorted way 
void sortedInsert(struct stack **s, int x) 
{ 
    // Base case: Either stack is empty or newly inserted 
    // item is greater than top (more than all existing) 
    if (isEmpty(*s) || x > top(*s)) 
    { 
        push(s, x); 
        return; 
    } 
  
    // If top is greater, remove the top item and recur 
    int temp = pop(s); 
    sortedInsert(s, x); 
  
    // Put back the top item removed earlier 
    push(s, temp); 
} 
/*
30 15 10 5 3 1 
40 
 40 15 5 30 1 50 

100 ok
아 이건 sotted된 상태에서 insert를 하는거구나 
애초에 넣어줄떄 제대로 넣어주면 되는거라서 다 뺀상태에서 

*/




// Function to sort stack
// 디 꺼내논담에 insert를 한하는데 
// sortedinsert에서 넣어야하는 기능은 제자리를 찾아가느넉지 
// 제자리 찾는게 어디까지냐면 내보다 작은애를 찾을떄까지  
void sortStack(struct stack **s) 
{ 
    // If stack is not empty 
    if (!isEmpty(*s)) 
    { 
        // Remove the top item 
        int x = pop(s); 
  
        // Sort remaining stack 
        sortStack(s); 
  
        // Push the top item back in sorted stack 
        sortedInsert(s, x); 
    } 
} 
  
// Utility function to print contents of stack 
void printStack(struct stack *s) 
{ 
    while (s) 
    { 
        printf("%d ", s->data); 
        s = s->next; 
    } 
    printf("\n"); 
} 
  
// Driver Program 
int main(void) 
{ 
    struct stack *top; 
  
    initStack(&top); 
    push(&top, 30); 
    push(&top, -5); 
    push(&top, 18); 
    push(&top, 14); 
    push(&top, -3); 
  
    printf("Stack elements before sorting:\n"); 
    printStack(top); 
  
    sortStack(&top); 
    printf("\n\n"); 
  
    printf("Stack elements after sorting:\n"); 
    printStack(top); 
  
    return 0; 
} 
/*
sort a stack using recursion 
recursion을 통해서 sorting을 stack에서한다 
아니면 애초에 값을 다 꺼내서 정렬 후 다시넣거나 

pop을 계속하겠지 
pop을 통해서 값을 보고
*/