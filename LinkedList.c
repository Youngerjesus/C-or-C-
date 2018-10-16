#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next; 
}Node; 


//코어 솔리디티 프로그래밍 ㅡtru
int main(){
    Node *head= NULL; //head가 있어야하는 이유가 newNode에서 node를 생성할때마다 시작점의 주소에서부터 이어야하니까 head가 있어야한다 
    Node *tail = NULL; 
    Node *cur = NULL;  //cur이 왜 있는지에 대해서 생각해보자 .
    
    Node *newNode = NULL;
    int readData; 

    while(!) {
        printf("data 입력 \n");
        scanf("%d", &readData*);

        if(readData <1 ) break; 
        
        newNode = (Node*)malloc(sizeof(Node));
        newNode.data = readData; 

        // cur = head->next;
        // while(cur != NULL){

        //      //잘못된거같ㅇ느데  // next의 이동을 내가 생각해봐야겟지 .연결리스트를 큐처럼 쓰는거와 연결리스트를 스택처럼 쓰는거 
        //     //이렇게 node, node - node->next
        //     cur = cur->next;
        // }

        if(head == NULL) { // 이 부분도 중요하게 설명했던것같다 .head가 비어있다면 head 에다가 넣어줘야한다 .
            head = newNode;  // insert를 할 때 중요한건 next를 이용한거다  근데 이 원본이 비어ㅗ있다면 거기에 넣어줘야하느게 너무 당연

        }
        else 
            tail->next = newNode; 

        tail = newNode; 
    
    }

    if(head == NULL) {
        printf("저장되지 않았다라는걸 의미 \\ㅜ")
    }
    else {
        Node *delNode= head;
        Node *delNodeNext = head->next; // 해제한다라는것 자체가 비운다는뜻 비우기전에 복사해놔야한다
        
        free(delNode);

        while(delNodeNext != NULL){
            delNode = delNodeNext; 
            delNodeNext = delNodeNext->next; 
            free(delNode);
        }
    }
    return 0;
}