// A structure to represent a stack 
struct StackNode 
{ 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = 
              (struct StackNode*) malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode *root) 
{ 
    return !root; 
} 

//stack은 마지막에 들어온애가 첫빠따가된다 . 그래서 개의 Next가 기존의것이 도니는거지 . LinkedList는 capacaity를 생각하지않아도되지.   
//첫 시작할때 root가 NULL이여도 상관없는거지 .  NULL에서 뭘가리키는건 상고나
void push(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop(struct StackNode** root) 
{ 
    //애초에 isEmpty(*root)를 바로하네... <-> queue와 비교래보면다면 
    if (isEmpty(*root)) 
        return INT_MIN; 

    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) //항
        return INT_MIN; 
    return root->data; 
} 
  
int main() 
{ 
    struct StackNode* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    printf("%d popped from stack\n", pop(&root)); 
  
    printf("Top element is %d\n", peek(root)); 
  
    return 0; 
} 