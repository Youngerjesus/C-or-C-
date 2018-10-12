
/*
bfs()자체가 모든방향을
*/
#include <iostream>
#include <deque>
#include <string>
#include <memory.h>
#include <stdlib.h>

using namespace std;

enum direction {NORTH, EAST , SOUTH, WEST};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0}; // dy dx는 방향을 의미한다 
bool wmap[51][51]; 
bool flag[50][50][4]; // 뒤에 4는 뭘까?
int m,n,e1,e2;

deque <int> x,y,step;
deque <direction> dir; 

/*
bfs()에서 중요한게 push랑 pop이랑 같이두는것 한 함수에서
문제가생기지않는다면 push 문제가생긴다면 pop 
두개의흐름을 만들필요가없는거지 병렬적이지않는거지
 반복문에 두개의함수가있다면 개별적으로실행도는데

 int bfs() void bfs() pop이다되는순간이
*/
int bfs(){
    //0인경우도 제거하네
    // 현재 로봇의 위치가 벗어난경우 
    if(x.front() <= 0 || y.front() <= 0 || x.front >= n ||
    y.front() >= m) {
        x.pop_front();
        y.pop_front();
        dir.pop_front();
        step.pop_front();
        
        return 0;
    }

    //현재 로봇이 이동한 위치에 장애물이 있는경우 
    if(wmap[y.front()][x.front()] == 1) {
        x.pop_front();
        y.pop_front();
        dir.pop_front();
        step.pop_front();
    
        return 0;
    }

    //이미 방문한 곳인지 
    if(flag [y.front()][x.front()][dir.front()] != 0 ){
        x.pop_front();
        y.pop_front();
        dir.pop_front();
        step.pop_front();
        
        return 0;
    }

    if(y.front() == e1 && x.front() == e2) return 1; 

    flag[y.front()][x.frotn()][dir.front()] =1; 
    //dir을 왜 flag에저장하냐
}

int main() {
    int i,j
    bool map[50][50]; 
    int result = 0 ;
    int b1,b2; 
    string direct ;

    while(cin >> m >> n ) {
        if(m == 0 && n == 0 ) break;

        memset(flag, 0 ,sizeof(flag));
        memset(wmap, 0 , sizeof(wmap));

        for(int i=0;i<=n;i++){
            wmap[0][i] = 1;
            wmap[m][i] = 1;
        }

        for(int i=0;i<=m;i++){
            wmap[i]0i] = 1;
            wmap[i][n] = 1;
        }

        //모두 pop이된다 = 가망이없다 
        // 왜 여기선 void bfs 가아니라 int bfs라고했을까 

        while(!y.empty()) {
            result = bfs(); 
            if(result == 1) break; 
        }
        
    }

}