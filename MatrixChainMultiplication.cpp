

/*
matrix는 결합법칙이 성립한다 .
근데 operation 숫자가 다르다. 라는거지 matrix간에 

optimazition 
subprobelm

row col * row * col  -> row col 
row col 만 생각해보면된다 .
arr row col row col row col row col 
row 
for (i +=2 ) {
    for( j += 2 ) { 
        minOpeation을 찾아내서 연산을 수행해내는것 
        arr이 동적으로 계속 재할당 되야겠지/ 
    }
}

bottom up  게속해서 제일 작은연산을 찾아내는거지 . 근데 이건
greedy 알고리즘이 아닌가 

top down = optimalzation
이 방법 TOp down에대해서 생각해봐야한다 .
대략적인 개요만 가지고 있지 그 다음에 대해서 생각안하고 있다이가
Dynamic Programiing 

find optimal 
모든상황을 다 고려해서 그중에서 최선을 선택하는거잖아.
매번 최선에 최선은 greedy 

DP의 매번 정해진 형식을 고수한다.
m  row  *  col 
DP에대해서 알고가자 

 
result = m *  DP() 
return result 

문제점
1. row1 col1 row2 col2 row3 col3 에서 col 과 row 는 같기떄문에 변수숫자를 줄여도된다
    row1 (col1=row2) (col2=row3) col3 
    matrix -> row1 col1 row2 col2 row3 col3 으로 복귀가능하네 
    matrix복구안해도되겠느데 

하나씩 하나씩 다 떼서 분리시키면될려나 
MatrixChainOrder(int p[] , int i ,int j )
2. 두가지방향 recursion 
1~n까지있다고 할떄
recursion을 n-1 
1-> n까지로 커지면서 recursion을 해도되지.
이게 recursion방향이랑 subproblem을 푸는방향이랑 같아야한다 .
recurision을통해서 모든 계산이 다 들어가야한다 .

1~5
recursion 
count = 123 
count = 234
count = 345

min과 count를 비교 

10 20  20 30  
10 30 30 20 

*/

#include<stdio.h> 
#include<limits.h> 
  
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
int MatrixChainOrder(int p[], int i, int j) 
{ 
    if(i == j) 
        return 0; 
    int k; 
    int min = INT_MAX; 
    int count; 
  
    // place parenthesis at different places between first 
    // and last matrix, recursively calculate count of 
    // multiplications for each parenthesis placement and 
    // return the minimum count 
    //subproblem에대한 result가 있어야하낟 .
    //어디까지 sub recursion인지 .
    //전체에서 recursion된ㄱㄹ
    for (k = i; k <j; k++) 
    { 
        //두가지방향이 있다!! 라느것 
        count = MatrixChainOrder(p, i, k) + 
                MatrixChainOrder(p, k+1, j) + 
                p[i-1]*p[k]*p[j]; 
  
        if (count < min) 
            min = count; 
    } 
  
    // Return minimum count 
    return min; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d ", 
                          MatrixChainOrder(arr, 1, n-1)); 
  
    getchar(); 
    return 0; 
} 