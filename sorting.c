
/*
그러니까 
첫번째줄이 객체의 수를 말하고 
두번째줄이 객체를 나타내는 특징을 말하고 
세번째가 examole 객체를 말한다 

객체의 수는 1000 <= <-= 500000 개가 있고
객체의 특징은 1<= <=10을 말하고 
이 객체의 특징은 최대 15글자를 넘지 않는다를 말한다 

멀가지고 정렬을 할건데를 묻는데  key값을 기준으로 정렬을 한다는거가 
(Key)라고 붙은걸 기준으로 정렬을 시켜야한다 이거네 

attribute의 개수를 세고 이 attribute에서 key값을 기준으로 정렬을하고 
attribute가 몇개인지를 기준으로 : 센다 

ch= == $이거냐 :이거냐를 기준ㅇ로 나눠줘야한다. 
chㅢ 개수가 3개임을 알고 그걸 기준으로 :으로 나누고 
그다음 : 이걸 기준으로 반복을하고  (key)라는 걸 찾아야하니까 
문자열 매칭과 관련된 함수를 써야하는데 
$민니먄 넘어가면 된다 

이차원배열마큼 동적할당을 하면되네 attribute에서 
attribute의 수가 m이되고 행이되고
object의 수가 n이된다 .? 
삼차원 배열로할경우 
object [1] [m] [length]

while이 어디까지 돌고 어디서 끝맺어야할까 
attribute의 긑을 어떻게 알까? $나올떄까지고 
그다음에 구분자가 : 기준으로 구분한다 . 
:랑 \n으로 구분된다 object가 
기본적으로  :로 각 attrubyte 간이 구별되고 
object에서 다음 object로 넘어갈떄는 \n으로 구부된다 .

object[][][]  이 있을떄 
object[1] <-> &object[1] 
key

testindex를 기준으로 정렬을해야하는데 
1,2,3,  n^n개가된다 시간복잡도를 계산하면 
n개가되도록 해야지 
n*n개가도ㅓ

kk개가 ii개랑 달라?  
먼가꼬였다 

object에서 kk
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sorting( int low, int high);
int Partition( int low, int high);
void swap(char *a, char *b);

char indexObject[500000][15]; //key값을 기준으로 열을 받아올 array 
char sortObject[500000][10][15]; // 정렬된 이후에 담겨질 object
char object[500000][10][15]; //attribute length max Size 1<= m <=15 
							 // object maxsize 1000 <= n <= 500000
							 // the number of attribute for eachs object 1<= t <= 10 

int main() {
	FILE *fp, *fpw;
	char ch;
	char *str; //find key 
	int index;
	int ii, jj, kk;
	int i, j, k;

	i = 0; // number of object 
	j = 0; // number of attribute
	k = 0; // length of attribute 

		   // kk ii jj is inex for loop 
	kk = 0;
	ii = 1;
	jj = 0;

	// index is find key 
	index = 0;

	fp = fopen("testinput1.txt", "r");
	fpw = fopen("hw1_output.txt", "w");


	fscanf(fp, "%d", &i);

	//find first '$' 
	fread(&ch, sizeof(char), 1, fp);
	fread(&ch, sizeof(char), 1, fp);
	fread(&ch, sizeof(char), 1, fp);

	// loop  until second '$'
	while (ch != '$') {
		fscanf(fp, "%c", &ch);
		if (ch != ':' && ch != '$') {
			object[0][j][k++] = ch;
		}
		else {
			j++;
			k = 0;
		}
	}

	// file에 있는 데이터를 object에 옮기는 과정
	while (fread(&ch, sizeof(char), 1, fp)) {
		if (ch == '\n') {
			ii++;
			jj = 0;
			kk = 0;
			continue;
		}
		if (ch == ':') {
			jj++;
			kk = 0;
			continue;
		}
		object[ii][jj][kk] = ch;
		kk++;
	}

	printf("check file data------\n\n");
	for (ii = 2; ii <= i + 1; ii++) {
		for (jj = 0; jj < j; jj++) {
			for (kk = 0; kk < strlen(object[ii][jj]); kk++) {
				printf("%c", object[ii][jj][kk]);
			}
			printf(":");
		}
		printf("\n");
	}

	//find key 
	for (jj = 0; jj < j; jj++) {
		str = strstr(&object[0][jj][0], "(Key)");
		// str이 null일경우 처리해주는것 중요 
		if (str != NULL && (strcmp(str, "(Key)") == 0)) {
			index = jj;
			break;
		}
	}

	for (ii = 2; ii <= i + 1; ii++) {
		for (kk = 0; object[ii][index][kk] != '\0'; kk++) {
			indexObject[ii-2][kk] = object[ii][index][kk];
		}
	}

	//key를 기준으로 indexObject sorting 
	sorting(0, i-1);
	
	//sorting object 이후 sorting object에 저장 
	for (ii = 2; ii <= i + 1; ii++) {
		for (int i2 = 0; i2 < i; i2++) {
			if (!strcmp(indexObject[i2], object[ii][index])) {
				//같은구간까지 찾을거잖아 
				for (jj = 0; jj < j; jj++) {
					strcpy(sortObject[i2][jj], object[ii][jj]); //strcpy로 sortobject에다가 모두 복사 
				}
			}
		}
	}

	// sorting object를 출력  
	printf("\nsortt-------\n\n");
	for (ii = 0; ii < i; ii++) {
		for (jj = 0; jj < j; jj++) {
			for (kk = 0; kk < strlen(sortObject[ii][jj]); kk++) {
				printf("%c", sortObject[ii][jj][kk]);
			}
			printf(":");
		}
		printf("\n");
	}



	//파일출력 
	for (ii = 2; ii <= i + 1; ii++) {
		for (jj = 0; jj < j; jj++) {
			for (kk = 0; kk < strlen(sortObject[ii][jj]); kk++) {
				fwrite(&sortObject[ii][jj][kk], sizeof(char), 1, fpw);
			}
			if (jj != j - 1) {
				fwrite(":", sizeof(char), 1, fpw);
			}
		}
		fwrite("\n", sizeof(char), 1, fpw);
	}


	fclose(fp);
	fclose(fpw);
}

int compare(const void *a, const void *b) {
	return strcmp((char*)a, (char*)b);
}

void sorting( int low, int high) {
	// 비교를 해야곘지 그걸 위해서 strcmp  a > b인 경우로 정렬하자 
	//한 문자열식 비교해본다고 햇을떄 나보다 더 작아? 그럼 너가 일로와야지  이렇게 삽입정렬식으로 정렬한다면 O(N^2)
	//Quicksort식으로 정렬을 하랄면 pivor 

	if (low < high) {
		int pi = Partition( low  ,high);
		sorting( low, pi - 1);
		sorting( pi + 1, high);
	}
}

int Partition( int low, int high) {

	char pivot[15]; 

	strcpy(pivot, indexObject[high]);
	
	int j = low-1; // j를 low로 뒀으 경우와, low-1로 둿으 때 차이는? 
	for (int i = low; i<high; i++) {
		//작은애를 찾은경우 
		if (strcmp(indexObject[i], pivot) <= 0) {
			j++;
			swap(indexObject[i], indexObject[j]);
		}
	}
	swap(indexObject[j + 1], indexObject[high]);
	return j + 1;
}

void swap(char *a, char *b) {
	char str[15];

	strcpy(str, a);
	strcpy(a, b);
	strcpy(b, str);
}

/*
low 와 high를 받는다 
pivot을 정하고 pivot보다 낮은데 오른쪽에 있다 => low 
좀만 더 생각해보면 pivot을 기준으로 나눈다고했다 
어디서 비교순위가 줄어드는지를 모른다 \
일반 삽입정렬은 그녀석의 정확한 위치만알지 그녀석을 기준으로
큰녀석들 작은녀석들 구분을 못한다 근데 이렇게 구분을해도 결국 비교횟수는ㄱ
같을거가은데 아 다르네 
이게 자기보다 큰애 자기보다 작은애 이렇게 나눠저있으면 
개수가 2개로 될떄 한녀석을 정리하면 나머지녀석도 차레대로 정렬이되네 
partition이 되지않고는 나눌 수 없다 .
큰 작은 작은 큰 큰 큰 작은  pivot 
작으 작은 작은 큰 큰 큰 큰 이 렇게 바꿔야한다
이 큰 샛기를 pivot과 비교하는데 적당한 인덱스로 넣어줘야하거든 
작은애를 만나면 작은애랑 바꿔주면되겠네 
큰애는 가지고 있고 작은애만 계속생각해보자 . 
i와 j의 정확한 index에대해서 생각해보자  i와 j가 둘다 ㅏㄱ으애의경우 
*/