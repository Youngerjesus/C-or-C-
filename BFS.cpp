

#include <stdio.h>
#include <iostream>

using namespace std;

int n, cnt;
int a[5][5];
int x[25], y[25],l[25];
/*
class Maze {
    public: 
        int x,y,l;
        Maze(int xx, int yy){
            this->x = xx;
            this->y = yy;
            this->l = 0; 
        }
        //여기서 class 에서 sorting하는것 비교해보자 
        // Maze에서 sorting은 l을 하고싶다 l에있는값은 아주다양해진다 
        // cnt하나마다 하나씩 
}
*/
void push(int xx, int yy, int ll ){
    x[cnt] = xx;
    y[cnt] = yy;
    z[cnt] = ll;
    cnt++;
}

void BFS() {
    int pos;
    x[0] = 0;
    y[0] = 0;
    l[0] =0;
    pos = 0;
    cnt = 1; 

    // pos < cnt는 벽에 계속막히는경우 pos만 증가하고 이동한다면 
    while(pos < cnt && (x[pos] != n-1 || y[pos] != n-1) ){
        a[y[pos]][x[pos]] = 0 ;

        if(y[pos] > 0 && a[y[pos]-1]x[pos] == 1){
            push(x[pos], y[pos]-1, l[pos]+1);
        }
        if(y[pos] < n-1 && a[y[pos]+1]x[pos] == 1){
            push(x[pos], y[pos]+1, l[pos]+1);
        }
        if(x[pos] > 0 && a[y[pos]]x[pos-1] == 1){
            push(x[pos]+1, y[pos], l[pos]+1);
        }
        if(y[pos] <n-1 && a[y[pos]]x[pos+1] == 1){
            push(x[pos]-1, y[pos], l[pos]+1);
        }

        pos++;
    }

         if(pos < cnt ) cout <<l[pos] <<endl;
   
}
/*
class로 만들어서 l이 더작은걸 
길가는거에 대해서 생각해보면 한번 지나간점이라면 0을 둔다고 했는데 
그러면 최단거리를 할 수 없잖아 다시 방문하는게 안되니까 
이런 점은 어떻게하지  sort가 될까 v.begin v.end
*/