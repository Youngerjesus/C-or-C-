// 값을 구하는문젠대 순환식을 memorization이나 bottom up 방식으로 푼다 

/*
최적화문제 최소문제랑 최대값문제를 해결하는것 
subproblem 이 순환식이랑 관련이 있는거지 . 큰 문제를 해결하는데
작은 문제와 겹치는거지 .=> 작은 문제가 기본문제랑 겹쳐져있는것 
그 문제의 최적해가 작은 문제에서의 최적해가 되어야한다. 

아 최장경로의 문제는 어떻게 구하는지알겠다 
 1 -> 4까지의 최장경로
 1 -> 3 까지의 최장경로 근데 4를 지나면안ㅇ됨
 1 -> 2 까지의 치장경로 근데 4와 3을 지나면안됨 

x 와 y의 문자열을 주어졌을경우 
순환식을 세우고 최적해를 찾는다라 ...  subproblem에서도 최적해가있어야한다라는거다
 한글자씩을 찾아

일반적인
L(i,j)  , L(i-1, j-1) +1   , max(L(i-1, j) , L(i, j-1 ))이 
둘 중에서 최장경로를 구해야한다 .
i 와 j 둘중에서 recursion을 반복하면 basecase에 도달한다. 
*/

//Longest Commomn subsequence 
//아 두 문자열중에 공통 부분문자열을 찾는거구나 . 


/* Dynamic Programming C/C++ implementation of LCS problem */
#include<bits/stdc++.h> 
   
int max(int a, int b); 
   
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n]; 
} 
   
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
   
/* Driver program to test above function */
int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
   
  int m = strlen(X); 
  int n = strlen(Y); 
   
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  
  return 0; 
} 


//recursion을 쓴거지 . 
int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 


int lcsOf3( string X, string Y, string Z, int m, 
                               int n, int o) 
{ 
    int L[m+1][n+1][o+1]; 
  
    /* Following steps build L[m+1][n+1][o+1] in 
       bottom up fashion. Note that L[i][j][k] 
       contains length of LCS of X[0..i-1] and 
       Y[0..j-1]  and Z[0.....k-1]*/
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            for (int k=0; k<=o; k++) 
            { 
                if (i == 0 || j == 0||k==0) 
                    L[i][j][k] = 0; 
  
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1]) 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 
  
                else
                    L[i][j][k] = max(max(L[i-1][j][k], 
                                         L[i][j-1][k]), 
                                     L[i][j][k-1]); 
            } 
        } 
    } 
  
    /* L[m][n][o] contains length of LCS for 
      X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
    return L[m][n][o]; 
} 
  
// memorization을 이용 .
int lcs(string X, string Y, int m, int n, int dp[][maximum]) 
{ 
    // base case 
    if (m == 0 || n == 0) 
        return 0; 
  
    // if the same state has already been 
    // computed 
    if (dp[m - 1][n - 1] != -1)  //이전에 값을 가지고 있다면 
        return dp[m - 1][n - 1]; 
  
    // if equal, then we store the value of the 
    // function call 
    if (X[m - 1] == Y[n - 1]) { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1, dp);  //값을 저장해두는거지 .
  
        return dp[m - 1][n - 1]; //늘 
    } 
    else { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = max(lcs(X, Y, m, n - 1, dp), 
                               lcs(X, Y, m - 1, n, dp)); 
  
        return dp[m - 1][n - 1]; 
    } 
} 