

// DP에서 recursion과 dp와의 차이는 뭔데 ?
// Memorization  피보나치함수에서 recursion을 이용하면 많은 계산이 중복된다 .
// 즉 이미 완료된 계산을 기억을 해둔다는것이 MEmoriztion이다 .

int fib(int n) {
    if(n == 1 || n ==2 ) return 1; 
    else if (f[n] > -1 ) return f[n]; 
    else {
        f[n] = fib(n-2) + fib(n-1);
        return f[n]; 
    }
}
// 중간계산결과를 caching을 함으로써 중복계산을피한다 .

/*
캐싱이되네.... 
배열 f가 -1으로 초기화되어있다고 가정한다 . 이건 건드렸나 안거드렸냐를 말하는거지 .

처음 진행과정에서 어떤흐름으로 넘어가는지만 생각해보면되겠디.  - 정확히 알고있으면 안들어도된다. 학습에 대한 과정이지. 
fib(6) fib(5) 
fib(6) fib (5) 
fib (5) fib (4)  -> 한 흐름에대해서 계산의 중복이 있음을 발견하고 
이 계산의 중복에대해서 해결해 놨으면 즉 한 흐름을 클리어했다면 다른 흐름에대해서는
계산의 중복이 없고 빠르게 처리가가능한거지  
그리고 이게 업데이트가되는것 

여기서 f[n] 의 f의 배열은 업데이트가 빠르게 되기위해서 전역으로 떄려야겠지 
전역으로 때리지않아도 되는구나 . 어짜피 주소를 넘기는거니까 . 주소안에 데이터를 써놓으면 주소만 복사되니까
데이를 읽는데는 전혀문제가없는거지 .


*/
// bottom - up 방식 
int fib2(int n) {
    f[1] = f[2] = 1; 
    
    for(int i ==3; i<=n;i++) {
        f[n] = f[n-1] +f[n-2]; 
    }
}

/*
진행흐름을 바꾸는것으로서 빠르게 memorization을 할 수 있는거지 .여기서는 
역으로가면 더 빠르다는건 당연시하게 느껴진다 . 
근데 일반 진행흐름에서 부터 역으로가면 빠르겠다!! 라는 직관이 어떻게 느껴진다라는거지 
하부가 상위를 구성하고 있으니까 이렇게 생각할 수 있는거네 

*/

//이항계수 
int binomial(int n, int k ){
    if( n == k || n == 0 ) {
        return 1; 
    }
    else {
        return binomial(n-1, k) + binomial(n-1, k-1);
    }
}

/*
이것도 피보나치랑 같은거지 .어떻게 보면 
bottom - up 방식은 안되나  되나 . 
좀 더 많은 메모리공간이 필요할 것같다 .
n과 k에 따른 value가 정해지는 것이니까 그에따른 2차원배열을 통해서 botom방식을 하면 되거나 
memoriztation을 하면 될 것 같은데 .

이게 조합을 계산할떄는 되게 비효율적이다 100 C 98 을 계산한다고해보면
100 ! 를 직접 계산을 해야한다 . 이거자체가 말이 잘 안된다고 생각하며노딘다 .
필요없는계산이 너무나많기 때문이다 . 
축약된 식을 생각하면되지 . 
오버플로우도 생기네 이런 경우에는 
for (  n  ~  n-k까지   / k! ) 

*/

int binomial2(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    else if ( binom[n][k] > -1 ) return binom[n][k]; 

    else {
        binom[n][k] = binomial2(n-1, k) + binomial2(n-1, k-1);
        return binom[n][k]; 
    }
}

/*
여기서 생각보면 return benom[n][k] 부분과 if절 순서에 대해서 좀 더 생각해보자 
먼저 if절의 순서에대해서 생각해보자면 
앞의 두개는 상관없는데 마지막은 늘 마지막이어야한다 그것만 규ㅊㄱ이고 
return binom[n][k]에대해서 생각해보면  바로 완료되는경우 
이걸 bottom up 방식으로 할 때 
각 0 은 0으로 1 으로 seting을 해줘야할거같은데 
*/

int binomial3(int n, int k) {
    for (int i= 0; i<=n ;i++) {
        for(int j =0; j<=k && j<=i; j++) {
            if( k == 0 || n == k) binom[i][j] =1;
            else binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
        } // 여기조건이 좀 중요하지 
    }

    return binom[n][k]; 
}

/*
여기서 되게 중요한게 뭐냐면 binom을 통해서 구하는데 
매번 반복문은 돌아가야하는 단점은 있는거같은데 바로 아는 경우라면  빠르게 바로 처리해줄 수 없는건ㄱ 
이것도 memorization을 하는거지 
크게 흐름이 두개가이다 
1. 내가아는선에서 정리해야하느 경우 
    바로 리턴하면된다 .
2. 내가모르는 부분일경우 가장 빠르게 접근하는 방법 
    내가 모르는겨웅는 접근하기가 어렵다 사용자가 입려갷주지않는이상 컴퓨터가 인식하랄면 반복문을 돌릴 수 바껭없고
    그런경웅넨ㄴ 애초에 처리할 떄 기본의 루프엣 처리햊 느게 가장빠르다 .

DP 가 overhead가 없네  
overhead; 
cpu처리사용과 메모리사용등이 많아서 실행시간보다 더 걸리는 시간 부가적인시간을 말한다 .
memorization이 왜 top-down 인가 .위에서부터 아래로가는데 아는경우에 처리하고 넣어준다라는것 

*/