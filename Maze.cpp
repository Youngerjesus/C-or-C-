// Robot Project 
// 2차원 배열로 표현한다  0은 길 1은 벽을 의미한다 . 


// why 2배씩 하는 걸까  왜 2배씩 해놓은걸까
// 6이면 down과 left   
// 15면 up right down left 4가지 모두를 넣기위해 
// 미로를 그릴때 사용하는거같다 
// 미로그리기  OR연산으로 더하는것 되게 참신하네 그냥 더하는것도 
// 될텐데 

enum {
    UP =1,
    RIGHT =2,
    DOWN = 4,
    LEFT = 8, 
};

int CMaze::GetShape(int x, int y) {
int shape = 0;
if (m_arrayMaze[y][x] != 0) { // 벽이 있는 경우에만 경우의 수를 따진다.
if (y > 0 && m_arrayMaze[y-1][x]) // 위쪽에 벽이 있나?
shape |= UP;
if (y < MAZE_SIZE - 1 && m_arrayMaze[y+1][x]) // 아랫쪽에 벽이 있나?
shape |= DOWN;
if (x > 0 && m_arrayMaze[y][x-1]) // 왼쪽에 벽이 있나?
shape |= LEFT;
if (x < MAZE_SIZE - 1 && m_arrayMaze[y][x+1]) // 오른쪽에 벽이 있나?
shape |= RIGHT;
}
return shape;
}



void CMaze::ShortestPath() {
int i, j = 0;
int x, y;
int x1, y1;
while (m_arrayRecord[i] >= 0) {
    x = m_arrayRecord[i];
    y = m_arrayRecord[i+1];
    j = i + 2; // 한 좌표가 두개의 정수이므로 다음 좌표는 +2이다.
    while (m_arrayRecord[j] >= 0) {
        x1 = m_arrayRecord[j];
        y1 = m_arrayRecord[j+1];
        if (x == x1 && y == y1) // 같은 좌표 발견되면
            j = DeletePath(i, j); // 중복 경로 삭제
        j += 2;
    }
     i += 2;
    }
}