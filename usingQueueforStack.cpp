
/* Program to implement a stack using  
two queue */
#include<bits/stdc++.h> 
  
using namespace std; 
  
class Stack 
{  
    // Two inbuilt queues 
    queue<int> q1, q2; 
      
    // To maintain current number of 
    // elements 
    int curr_size; 
  
    public: 
    Stack() 
    { 
        curr_size = 0; 
    } 
  
    void push(int x) 
    { 
        curr_size++; 
  
        // Push x first in empty q2 
        q2.push(x); 
  
        // Push all the remaining  
        // elements in q1 to q2.  
        while (!q1.empty()) 
        { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        // swap the names of two queues 
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void pop(){ 
  
        // if no elements are there in q1  
        if (q1.empty()) 
            return ; 
        q1.pop(); 
        curr_size--; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
        return q1.front(); 
    } 
  
    int size() 
    { 
        return curr_size; 
    } 
}; 
  
// driver code 
int main() 
{ 
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
  
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
} 
// This code is contributed by Chhavi  
/*
stack은 뒤애서 
queue 앞에서부터

queue 1, 2, 3 
queue 1, 2, 3 이건 stack이랑 다르네 
q2 = q1이 되는거지 
q2에 push를 한다고 
q2에 1이 들어가는거지 
q1에 1이 들어간다  (q스왑)
q2에 2를넣으면 
q2에 2가들어간다 
2, 1이 들어간다 
q1에 2, 1
3이 들어가면 
3 , 2 , 1 

why? 
q1에 들어온 순서가 담겨있다 
q1에 1, 2, 3, 4 가아니라 4, 3, ,2 ,1 
q에 넣을라면 나중에껄 나중에 넣어주며노디겠지 
나중걸 나중에 담는다라

단일과정을 알겠는데 제네릭하게만드는거에 대해서 좀만 알면 되겠다 
먼저나가야하는애가 나중에들어온애가 되야하니까 큐에서는 애를먼저넣고 그다음

아직도 queue랑 스택이랑 헷갈려한다 
젤 나중에 드러온걸 먼저 빈 큐에 넣어줘야한다  빈큐가아니라면 그게 첫번쨰가 안되겠지 
저장해놔야하다
근데 이게 개수가 여러개가 되어서 된다ㅡㄴ건 첫번째의 경우도 무리없이 된다
 즉 n에서 되고 n+1이에서 된다라는건 n=2에서도 된다라는게 아닐ㄹ까 
 수학적 귀납법적인 증명으로 
 

*/