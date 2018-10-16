
/* C Program to implement a queue using two stacks */
#include <stdio.h> 
#include <stdlib.h> 
  
/* structure of a stack node */
struct sNode { 
    int data; 
    struct sNode* next; 
}; 
  
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data); 
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref); 
  
/* structure of queue having two stacks */
struct queue { 
    struct sNode* stack1; 
    struct sNode* stack2; 
}; 
// 
/* Function to enqueue an item to queue */
void enQueue(struct queue* q, int x) 
{ 
    push(&q->stack1, x); 
} 
  
/* Function to deQueue an item from queue */
int deQueue(struct queue* q) 
{ 
    int x; 
  
    /* If both stacks are empty then error */
    if (q->stack1 == NULL && q->stack2 == NULL) { 
        printf("Q is empty"); 
        getchar(); 
        exit(0); 
    } 
  
    /* Move elements from stack1 to stack 2 only if 
       stack2 is empty */
    if (q->stack2 == NULL) { 
        while (q->stack1 != NULL) { 
            x = pop(&q->stack1); 
            push(&q->stack2, x); 
        } 
    } 
  
    x = pop(&q->stack2); 
    return x; 
} 
  
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data) 
{ 
    /* allocate node */
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode)); 
    if (new_node == NULL) { 
        printf("Stack overflow \n"); 
        getchar(); 
        exit(0); 
    } 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*top_ref); 
  
    /* move the head to point to the new node */
    (*top_ref) = new_node; 
} 
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref) 
{ 
    int res; 
    struct sNode* top; 
  
    /*If stack is empty then error */
    if (*top_ref == NULL) { 
        printf("Stack underflow \n"); 
        getchar(); 
        exit(0); 
    } 
    else { 
        top = *top_ref; 
        res = top->data; 
        *top_ref = top->next; 
        free(top); 
        return res; 
    } 
} 
  
/* Driver function to test anove functions */
int main() 
{ 
    /* Create a queue with items 1 2 3*/
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
    q->stack1 = NULL; 
    q->stack2 = NULL; 
    enQueue(q, 1); 
    enQueue(q, 2); 
    enQueue(q, 3); 
  
    /* Dequeue items */
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
  
    return 0; 
} 
/*
tail을 두는게 아니라 sstack을 2개를 만든다 
enqueue stck 1에다가 data를 넣고 
newnode를 만들고
이 newNode안에 data를 넣는다 .
아 
struct sNode **top_ref에서 왜 **인지 알겠다
topref는 strcut *- > 변수 * 두번들어가는거니가 

그리고 push(q-> stack1) 이랑 무슨차이지 
q->stack1은 *주소 
주소에 주소를 들어가야하니까 &q->stack1 
q-stack1 -

top_ref->next  = newNode를 하고 
top_ref = newNode ?  
고유로 넘겨주는게 아니니까 
이 값은 처리가 안되겠지 
이건 애초에 연결리스트로만드는거랑 비슷한거가튼데 

newNode-> data 

top_ref-=  newNode

pop을 할 경우 
top= *topref
*topref  = topref->nextl
free(top)

stack s2는 왜 있느너지 그럼push push 
첫번쨰 부터 들어가서 가장 첫번쨰 -> 마지막 
stack 2에다가 ㅏ
뒤에서 빼는거가 

new_node = 늦게들어온애가 top이된다 .
젤 늦게들어온애부터 push한다 stack2에 
그럼 stack2에는 젤최근애부터 가득차지

아 근데 dqueue로 출력을하는구나 

*/