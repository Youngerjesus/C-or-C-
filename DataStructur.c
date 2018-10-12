#include "stdafx.h"
#include <stdlib.h>

#define MAX_SIZE 50000 
int sx, sy; //starting pointer 
int ex, ey; //ending pointrer

int stack[MAX_SIZE];
int l[MAX_SIZE];

char **maze;
int *warp;
int n, m;
int wi;
int w;
int top;
int distance; 

void push(int y, int x) {

	//스택에 x좌표와 y좌표를 더합니다 
	stack[top++] = y;
	stack[top++] = x;

	if (top > MAX_SIZE) {
		printf("stack overflow \n");
		exit(1);
	}
}
void pop(void) {
	if (top < 0) {
		printf("stack underflow\n");
		exit(1);
	}
	top -= 2;  //x와 y모두 빼줘야하니까 -2를 합니다 

	 
}
//cnt는 거리를 의미합니다 
void Find_ShortPath(int y, int x, int cnt) {
	if (y == ey && x == ex) {
		
		if (distance >= cnt) {
			distance = cnt;
			for (int i = 0; i< top; i += 2) {
				l[i] = stack[i];
				l[i + 1] = stack[i + 1];
			}
			pop();
			return;
		}
	}

	// 임시로 벽을 만들기 
	maze[y][x] = '*';
	
	//위로이동 
	if (y>0 && maze[y - 1][x] == '0') {
		push(y-1, x);
		Find_ShortPath(y - 1, x, ++cnt);
		cnt--;
	}
	//아래쪽으로 이동 
	if (y < n - 1 && maze[y + 1][x] == '0') {
		push(y+1, x );
		Find_ShortPath(y + 1, x,++cnt);
		cnt--;
	}
	//왼쪽으로 이동 
	if (x > 0 && maze[y][x - 1] == '0') {
		push(y , x-1);
		Find_ShortPath(y, x - 1, ++cnt);
		cnt--;
	}
	//오른쪽으로 이동
	if (x < m - 1 && maze[y][x + 1] == '0') {
		push(y, x+1);
		Find_ShortPath(y, x + 1, ++cnt);
		cnt--;
	}


	//위쪽에 워프가 있는 경우  
	if (y>0 && maze[y - 1][x] == 'w') {
		push(y - 1, x);
		maze[y - 1][x] = '*';
		for (int i = 0; i<w*2; i+=2) {
			if (warp[i] != y - 1 && warp[i + 1] != x) {
				push(warp[i], warp[i + 1]); //같은걸 push하지않나  2 ,0은 또 다른애랑도 다르지않나 
				Find_ShortPath(warp[i], warp[i + 1], ++cnt);
			}
		}
		pop();
		cnt--;
	}
	//아래쪽에 워프가 있는경우 
	if (y< n - 1 && maze[y + 1][x] == 'w') {
		push(y + 1, x);
		maze[y + 1][x] = '*';
		for (int i = 0; i<w*2; i+=2) {
			if (warp[i] != y + 1 && warp[i + 1] != x) {
				push(warp[i], warp[i + 1]);
				Find_ShortPath(warp[i], warp[i + 1], ++cnt);
			}
		}
		pop();
		cnt--;
	}
	//왼쪽에 워프가 있는경우  
	if (x > 0 && maze[y][x - 1] == 'w') {
		push(y, x - 1);
		maze[y][x - 1] = '*';
		for (int i = 0; i<2*w; i+=2) {
			if (warp[i] != y && warp[i + 1] != x - 1) {
				push(warp[i], warp[i + 1]);
				Find_ShortPath(warp[i], warp[i + 1], ++cnt);
			}
		}
		pop();
		cnt--;
	}
	//오른쪽에 워프가 있는경우  
	if (x<m - 1 && maze[y][x + 1] == 'w') {
		push(y, x + 1);
		maze[y][x + 1] = '*';
		for (int i = 0; i<w*2; i+=2) {
			if (warp[i] != y && warp[i + 1] != x + 1) {
				push(warp[i], warp[i + 1]);
				Find_ShortPath(warp[i], warp[i + 1], ++cnt);
			}
		}
		pop();
		cnt--;
	}

	
	maze[y][x] = '0';
	
	for (int i = 0; i < w * 2; i += 2) {
		if (warp[i] == y && warp[i + 1] == x) {
			maze[y][x] = 'w';
			cnt--;
		
		}
	}
	pop();
}

void Create_Maze(FILE *fp) {
	int i, j;
	char ch;

	if (fp == NULL) printf("입력 파일 열기 실패 \n");

	while (!feof(fp)) {
		fread(&ch, sizeof(char), 1, fp);
		if ((ch == '0' || ch == 'w' || ch == 's' || ch == 'e' || ch == '*')) m++;
		if (ch == '\n') n++;
	}
	

	fseek(fp, 0, SEEK_SET);

	// m은 총 글자수를 의미하므로 n만큼 나눠줘야합니다 
	n += 1;
	m = m / n;

	maze = (char**)malloc(sizeof(char*)*n);

	for (i = 0; i < m; i++) maze[i] = (char*)malloc(sizeof(char)*(m));

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fp, "%c ", &maze[i][j]);
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}

	// set 시작점 끝나는점 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (maze[i][j] == 's') {
				sx = j;
				sy = i;
				maze[i][j] = '0';
			}
			if (maze[i][j] == 'e') {
				ex = j;
				ey = i;
				maze[i][j] = '0';
			}

			if (maze[i][j] == 'w') {
				w++;
			}
		}
	}
	
	warp = (int *)malloc(sizeof(int) * w);

	//set Warp 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (maze[i][j] == 'w') {
				warp[wi++] = i;
				warp[wi++] = j;
			}
		}
	}

	//warp test 
	
	//check maze 

}
int main()
{
	FILE *fp, *fpw;
	fp = fopen("hw2_input.txt", "r");
	fpw = fopen("hw2_output.txt","w");

	if (fp == NULL) printf("입력 파일 열기 실패 \n");
	if (fpw == NULL )printf("출력 파일 열기 실패 \n");
	
	Create_Maze(fp);
	push(sy, sx);
	distance = n * m;
	Find_ShortPath(sy, sx,0);
	int i = 0;
	int j = 0;

	printf("\n%d\n", distance);
	for (; i <= distance; i++, j += 2) {
		printf("(%d ,%d) ", l[j] + 1, l[j + 1] + 1);
	}
	// 저는 첫좌표를  (0,0)을 기준으로 삼았기떄문에 모든 좌표를 +1만큼 평행이동 해줘야한다 . 
	fprintf(fpw,"%d\n", distance);
	for (; i <= distance; i++,j +=2) {
		fprintf(fpw,"(%d ,%d) ", l[j] + 1, l[j + 1] + 1);
	}

	fclose(fp);
	fclose(fpw);
    return 0;
}

