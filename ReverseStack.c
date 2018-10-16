

/*
Reverse 하는방법 
top에서 밑으로 쭉 들어가보면 되지  

if(top != 0 ) 
pop( top=1 )

return  stack[top]; 

*/


// C program to reverse a  
// stack using recursion 
#include<stdio.h> 
#include<stdlib.h> 
#define bool int 
  
// structure of a stack node  
// stack에서 *next를 쓰네 ...
struct sNode 
{ 
    char data; 
    struct sNode *next; 
}; 
  
// Function Prototypes  
void push(struct sNode** top_ref,  
                   int new_data); 
int pop(struct sNode** top_ref); 
bool isEmpty(struct sNode* top); 
void print(struct sNode* top); 
  
// Below is a recursive function 
// that inserts an element 
// at the bottom of a stack. 
void insertAtBottom(struct sNode** top_ref, 
                                 int item) 
{ 
    if (isEmpty(*top_ref)) 
        push(top_ref, item); 
    else
    { 
        // Hold all items in Function Call 
        // Stack until we reach end of the 
        // stack. When the stack becomes 
        // empty, the isEmpty(*top_ref)becomes 
        // true, the above if part is executed 
        // and the item is inserted at the bottom  
        int temp = pop(top_ref); 
        insertAtBottom(top_ref, item); 
  
        // Once the item is inserted  
        // at the bottom, push all 
        // the items held in Function  
        // Call Stack  
        push(top_ref, temp); 
    } 
} 

// 어떻게
// Below is the function that  
// reverses the given stack using 
// insertAtBottom() 
// recursion에대한 이해가 제대로되는지 
// rrr(r(r(ri)i)i)iiii
void reverse(struct sNode** top_ref) 
{ 
    if (!isEmpty(*top_ref)) 
    { 
        // Hold all items in Function  
        // Call Stack until we 
        // reach end of the stack  
        int temp = pop(top_ref); 
        reverse(top_ref); 
        //계속하나
  
        // Insert all the items (held in  
        // Function Call Stack) 
        // one by one from the bottom  
        // to top. Every item is 
        // inserted at the bottom  
        insertAtBottom(top_ref, temp); 
    } 
} 
/*
insertAtBottom  
*/
// Driver Code 
int main() 
{ 
    struct sNode *s = NULL; 
    push(&s, 4); 
    push(&s, 3); 
    push(&s, 2); 
    push(&s, 1); 
  
    printf("\n Original Stack "); 
    print(s); 
    reverse(&s); 
    printf("\n Reversed Stack "); 
    print(s); 
    return 0; 
} 
  
// Function to check if 
// the stack is empty  
bool isEmpty(struct sNode* top) 
{ 
    return (top == NULL)? 1 : 0; 
} 
  
// Function to push an item to stack 
void push(struct sNode** top_ref,  
                    int new_data) 
{ 
      
    // allocate node 
    struct sNode* new_node = 
        (struct sNode*) malloc(sizeof(struct sNode)); 
  
    if (new_node == NULL) 
    { 
        printf("Stack overflow \n"); 
        exit(0); 
    } 
  
    // put in the data  
    new_node->data = new_data; 
  
    // link the old list  
    // off the new node  
    new_node->next = (*top_ref); 
  
    // move the head to  
    // point to the new node  
    (*top_ref) = new_node; 
} 
  
// Function to pop an item from stack 
int pop(struct sNode** top_ref) 
{ 
    char res; 
    struct sNode *top; 
  
    // If stack is empty then error  
    if (*top_ref == NULL) 
    { 
        printf("Stack overflow \n"); 
        exit(0); 
    } 
    else
    { 
        top = *top_ref; 
        res = top->data; 
        *top_ref = top->next; 
        free(top); 
        return res; 
    } 
} 
  
// Function to print a 
// linked list  
void print(struct sNode* top) 
{ 
    printf("\n"); 
    while (top != NULL) 
    { 
        printf(" %d ", top->data); 
        top = top->next; 
    } 
} 

/*
push에대해서 좀 생각해보면 
newNode를 만들고 
이 newNode가 top이되어야지 
newNode.data =data;
 
newNode-> next = top_ref; 
newNode = top_Ref;

insertAtBottom
1, 2, 3,  3 , 2 , 1 4  3 , 2 , 1 

stack을 queue로 바꾼다면 가능한거같은데 reverse는

어떻게 넣느냐에 따라서 순서가 정해진다 들어가는 순서가 정해진다 
씨발 stack만 한바가지네 
queue랑 연결리스트랑 할거 많은데
스택을 다꺼내서 다시넣어준다고 생각해보자  
1 ,2 ,3, ,5, ,6, 7, ,8, ,9 ,10 
가장 마지막에 꺼낸거 1이다 이걸 쌓아서 넣으면 그대로 
1, 2, 3, 4, 5, ,6 ,7 8, ,9, 10이 되는데
뺴자마자 넣으면 
10, 9, 8, 7, 6, 5, 4, 3 ,2 ,1,이 된다 

3 ,2 1 

4, 

재귀의순서를 기억핺으면되네 
*/