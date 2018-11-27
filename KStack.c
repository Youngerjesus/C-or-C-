


/*
two stack in a single array에서 구현할라면 
top과 bottom을 둘다 만들어서 둘의 인덱스가 겹치지않게 
top 에서 한칸더가면 bottom으로 들어가지앟게 구현햇다

하나의 싱글어레이엣허 2개의 stack이아니라 k개의 stack을 효율적으로
구현하는거에 대해서 생각해봐야한다
 
 method1이 하나이 싱글어레이에 크기의 n을 k배조 쪼개는것
 여기서 중요한게
 난 잉여공간을 최소한으로 하면서 만듷고싶다
 그럴 경우 시작 top을 균등하게 배분하면 안도지

 한쪽방향 -> 
 다른 쪽 방향은 <- 이걸 세트로 한다고했을떄도 problem이 생긴다 
 한세트가 압도적으로 많은경우 
 다른 set의 영역까지 같이 쓰고시팓 ./
 그냥 stack을 쌓을때 

 *next를 이용한다던데 
 
*/

#include<iostream> 
#include<climits> 
using namespace std; 
  
// A C++ class to represent k stacks in a single array of size n 
class kStacks 
{ 
    int *arr;   // Array of size n to store actual content to be stored in stacks 
    int *top;   // Array of size k to store indexes of top elements of stacks 
    int *next;  // Array of size n to store next entry in all stacks 
                // and free list 
    int n, k; 
    int free; // To store beginning index of free list 
public: 
    //constructor to create k stacks in an array of size n 
    kStacks(int k, int n); 
  
    // A utility function to check if there is space available 
    bool isFull()   {  return (free == -1);  } 
  
    // To push an item in stack number 'sn' where sn is from 0 to k-1 
    void push(int item, int sn); 
  
    // To pop an from stack number 'sn' where sn is from 0 to k-1 
    int pop(int sn); 
  
    // To check whether stack number 'sn' is empty or not 
    bool isEmpty(int sn)  {  return (top[sn] == -1); } 
}; 
  
//constructor to create k stacks in an array of size n 
kStacks::kStacks(int k1, int n1) 
{ 
    // Initialize n and k, and allocate memory for all arrays 
    k = k1, n = n1; 
    arr = new int[n]; 
    top = new int[k]; 
    next = new int[n]; 
  
    // Initialize all stacks as empty 
    // Next가아닌 before이람ㄴ  어짜피 top은 여러개 

    for (int i = 0; i < k; i++) 
        top[i] = -1; 
  
    // Initialize all spaces as free 
    free = 0; 
    for (int i=0; i<n-1; i++) 
        next[i] = i+1; 
    next[n-1] = -1;  // -1 is used to indicate end of free list 
} 
  
// To push an item in stack number 'sn' where sn is from 0 to k-1 
void kStacks::push(int item, int sn) 
{ 
    // Overflow check 
    if (isFull()) //full은 free free변수는 뭔지
    { 
        cout << "\nStack Overflow\n"; 
        return; 
    } 
  
    int i = free;      // Store index of first free slot 
  
    // Update index of free slot to index of next slot in free list 
    free = next[i]; 
    // free가 다음 index를 말하는거같은데 
    // 애초에 다음 인덱스를 해주고 자기는 before로 돌아가도록 하는거네 
    // Update next of top and then top for stack number 'sn' 
    next[i] = top[sn]; 
    top[sn] = i; 
  
    // Put the item in array 
    arr[i] = item; 
} 
// next[i] top[sn] 이전의 top이 되겠지 .
//   
// To pop an from stack number 'sn' where sn is from 0 to k-1 
int kStacks::pop(int sn) 
{ 
    // Underflow check 
    if (isEmpty(sn)) 
    { 
         cout << "\nStack Underflow\n"; 
         return INT_MAX; 
    } 
  
  
    // Find index of top item in stack number 'sn' 
    int i = top[sn]; 
  
    top[sn] = next[i];  // Change top to store next of previous top 
  
    // Attach the previous top to the beginning of free list 
    next[i] = free; 
    free = i; 
  
    // Return the previous top item 
    return arr[i]; 
} 
  
/* Driver program to test twStacks class */
int main() 
{ 
    // Let us create 3 stacks in an array of size 10 
    int k = 3, n = 10; 
    kStacks ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
} 

/*
여러개의 top은 시작점을 나타내준다. top[0] top[1] 
1번스택이 0, 5, 10 인덱스 
next[10] = 5;
next[5] = 0; 
next[0] = 0;  //애초에 -1을 넣는게 낫지 않나 
before형식처럼 할라면 

arr[0] = data1. top[0] = 0; next[0] = 0
arr[1] = data2; top[1] = 1; ne//끝은 몇번 스택을 쓸건지를 말함 
arr[2] = data3; top[3] = 2; 
arr[3] = data1; top[0] = 3; next[3] =  0  //여기만 넣어줄순없다 general에선
arr[4] = data1; top[0] = 4; next[4] = 3; 

항상 코딩에선 2부분으로 나뉘는거같다 . 
시작하는 부분과 이어지는 부분과 머무리 부분 .


push :  
item 
sn : stack의 number을 말한다 .
arr: item 가 담길곳 
next: 초기화될떄 그 다음 index를 

int i = free; 
free = next[i] 매번받는다  // 이건 다음 루프에서 받는거지 

next[i] = top[sn]; 
arr[i] = item;  
내가 짠 마무리는 매번 마지막인지를 검사해야한다 .
여기서도 검사하는데 isFull()함수로 검사하는데 

pop()을할 때 생각해야하는데 
free는 next index니까 
free에서 1을 뺸것이 지금 까지 넣었던 인덱스가 되고 
지금까지 넣었던 인덱스는 별로 필요가없지 .
왜냐하면 내가 어떤 stack에서 숫자를 뺴는지 넣는지가 중요한거니까 
어떤 top에서 뺄건지가 중요하겠지 .
근데 pop을 할 때 맨 끝엘서만 빼면 당연히 좋은데 
그게아니라면 중간에 구멍이 생기는건데 그럼 이 구멍도 채워야하는건데 
누가 채우는데 이건 뻇던 stack에서 채우면 당연히 좋겠는데 
그러지 못하는경우도 있지 배제할 순 없지 .
아 
왜 free를 쓰는지 알겠다 .
이게 왔다갔다 하네 인덱스가 넣어줘야하는 인덱스가 

pop[sn]

free = top[sn]; //top[sn이 사라지는거니까 ]
top[sn]  =  next[free]
이게 끝아닌가 ? 
next[free]자체가 값이 바껴야한다 .
멀로  비어있는공간에서부터 내가 채워넣어야하는공간 
top[sn]을 비웠기떄문에 여기서 비워줬다가 다시 되돌아가야한다 .
next[i] = free; 현재 인덱스가아니라  
free = i; 

내가 기본 loop에 애초에 변수하나로 깔끔하게 하느게나은거지
 현재인덱스가 필요한게 아니라 다음 인덱스가 주로 쓰인다면
 현재인덱스 +1 이런ㅅㄱ으로 할 필요는 없지 가독성을 위해서 
 



*/